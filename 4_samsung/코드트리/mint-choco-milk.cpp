#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

const int MX = 51;
int N, Days, F[MX][MX], B[MX][MX]; // F를 int로 민1 초2 우유4 
string map[MX]; // F를 위해 별도 처리, 2개 이상의 음식은 비트OR연산
bool vis[MX][MX], defense[MX][MX]; // 방문이랑 전파 여부 분리

// {(음식수, -대표B) (행, 열)} 신앙심은 큰것부터, 좌표는 작은 것부터라서
vector< pair< pair<int, int>, pair<int, int> > > leaderList;

// getGroup에서 탐색 중 구성원 정보 {(-B) (행, 열)} 임시 저장
vector< pair<int, pair<int, int> > > groupMembers;
int groupSize; // 현재 그룹의 학생수 저장

void input() {
	cin >> N >> Days;

	for (int i = 0; i < N; ++i) {
		cin >> map[i];

		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 'T') F[i][j] = 1;
			else if (map[i][j] == 'C') F[i][j] = 2;
			else if (map[i][j] == 'M') F[i][j] = 4;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> B[i][j];
	}
}

void print() {
	int Bsum[8] = {0}; // 7로 하면 사이즈 미스

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) Bsum[F[i][j]] += B[i][j];
	}

	// 민초우7 민초3 민우5 초우6 우4 초2 민1
	cout << Bsum[7] << " "
		<< Bsum[3] << " "
		<< Bsum[5] << " "
		<< Bsum[6] << " "
		<< Bsum[4] << " "
		<< Bsum[2] << " "
		<< Bsum[1] << "\n";
}

int countFoods(int Fval) {
	int cnt = 0;
	if (Fval & 1) cnt++; // if (Fval==1)이랑 달라
	if (Fval & 2) cnt++; // Fval에 2가 포함되어 있는지 확인 가능
	if (Fval & 4) cnt++;
	return cnt;
}

void getGroup(int y, int x, int startFood) {
	vis[y][x] = true;

	groupMembers.push_back({ -B[y][x], {y, x} });
	groupSize++;

	// dfs로 수행
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
		if (vis[ny][nx]) continue;
		if (startFood != F[ny][nx]) continue; // 같은 것만 그룹핑
		getGroup(ny, nx, startFood);
	}
}

void launch() {
	leaderList.clear();
	fill(&vis[0][0], &vis[MX - 1][MX], false);
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (vis[i][j] == true) continue;
			//vis[i][j] = true;

			groupMembers.clear();
			groupSize = 0;
			getGroup(i, j, F[i][j]); // 그룹화

			// 대표자 찾기
			sort(groupMembers.begin(), groupMembers.end());

			// 정렬 후 맨 앞 = 대표
			int kingY = groupMembers[0].second.first;
			int kingX = groupMembers[0].second.second;

			B[kingY][kingX] += groupSize;

			// 대표의 F에 포함된 기본 음식 T C M의 개수 
			int foodCount = countFoods(F[kingY][kingX]); // =ij
			leaderList.push_back({ {foodCount, -B[kingY][kingX]}, {kingY, kingX} }); //⭐-F 아니고 -B겠지...
		}
	}
}

void dinner() {
	// MCT처럼 음식종류 적은 순, -B로 신앙심큰순, 행, 열
	sort(leaderList.begin(), leaderList.end());
	fill(&defense[0][0], &defense[MX - 1][MX], false);
	
	int dir, power, kingY, kingX, nyy, nxx;
	for (int i = 0; i < leaderList.size(); ++i) {
		kingY = leaderList[i].second.first;
		kingX = leaderList[i].second.second;

		if (defense[kingY][kingX]) continue;

		nyy = kingY, nxx = kingX; // 시작 위치 

		dir = B[kingY][kingX] % 4;
		power = B[kingY][kingX] - 1;
		B[kingY][kingX] = 1;

		while (power > 0) {
			nyy += dy[dir];
			nxx += dx[dir];

			if (nyy >= N || nxx >= N || nyy < 0 || nxx < 0) break;

			if (F[kingY][kingX] == F[nyy][nxx]) continue;

			int targetB = B[nyy][nxx]; // 전파 대상의 B

			if (power > targetB) { // 강한 전파
				F[nyy][nxx] = F[kingY][kingX];
				B[nyy][nxx]+=1; // 대상 학생의 신앙심 +1
				
				// B를 갱신하는 게 아니라 power를 빼야 while이 끝나
				power -= (targetB + 1); // B[nyy][nxx]을 빼는 거랑 같아
			}
			else { // 약한 전파
				F[nyy][nxx] |= F[kingY][kingX]; // 비트 연산으로 킹+내거
				B[nyy][nxx] += power; //⭐targetB에 갱신X
				power = 0;
			}

			defense[nyy][nxx] = true; // 전파됨

			if (power == 0) break; // pwr > 0지만...
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	input(); 
	while(Days--) {
		launch(); // 그룹화 + 대표선정
		dinner(); // 대표가 전파
		print();  // 매일 음식별로 Bsum 계산 후 출력
	}

	return 0;
}