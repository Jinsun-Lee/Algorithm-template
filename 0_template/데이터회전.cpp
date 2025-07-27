#include <iostream>
#include <iomanip> // 숫자를 일정 너비로 맞춰 출력하려고
using namespace std;

#define MX 11
#define endl "\n"

int N, M, R;
int arr[MX][MX];
int tmp[MX][MX];

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M;j++) {
			//cout << arr[i][j] << " ";
			cout << setw(2) << arr[i][j] << " ";

		}
		cout << endl;
	}
}

void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M;j++) {
			arr[i][j] = tmp[i][j];
		}
	}
}

void flipV() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) tmp[N - i - 1][j] = arr[i][j];
	} copy();
}

void flipH() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) tmp[i][M - j - 1] = arr[i][j];
	} copy();
}

void turnCW() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) tmp[j][N - i - 1] = arr[i][j];
	} swap(N, M); copy();
}

void turnCCW() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) tmp[M - j - 1][i] = arr[i][j];
	} swap(N, M); copy();
}

void func5() {
	int n = N / 2;
	int m = M / 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			// 문제에서 알려주는대로 옮기면 이상함, 예제 보고 순서 확인해
			// 사용할 숫자를 범위에서 / tmp에서는 영역을 지정
			if (i < n && j < m)       tmp[i][j + m] = arr[i][j]; // 숫자1 영역2 
			else if (i < n && j >= m) tmp[i + n][j] = arr[i][j]; // 숫자2 영역4 
			else if (i >= n && j < m) tmp[i - n][j] = arr[i][j]; // 숫자3 영역1 
			else                      tmp[i][j - m] = arr[i][j]; // 숫자4 영역3 

		}
	} copy();
}

void func6() {
	int n = N / 2;
	int m = M / 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (i < n && j < m)       tmp[i + n][j] = arr[i][j]; // 숫자1 영역3
			else if (i < n && j >= m) tmp[i][j - m] = arr[i][j]; // 숫자2 영역1 
			else if (i >= n && j < m) tmp[i][j + m] = arr[i][j]; // 숫자3 영역4 
			else                      tmp[i - n][j] = arr[i][j]; // 숫자4 영역2 

		}
	} copy();
}

void turnSquareCW(int sy, int sx, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			tmp[j][len - i - 1] = arr[i + sy][j + sx]; // ROW 대신 len, i+sy, j+sx
		}
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			arr[i + sy][j + sx] = tmp[i][j];
		}
	}
}

void turnSquareCCW(int sy, int sx, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			tmp[len - j - 1][i] = arr[i + sy][j + sx];
		}
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			arr[i + sy][j + sx] = tmp[i][j];
		}
	}
}

void shiftCCW() {
	int layers = min(N, M) / 2; // 레이어의 수

	for (int k = 0; k < layers; k++) {
		int sy = k, sx = k;
		int ey = N - k - 1, ex = M - k - 1;

		// 첫 값 저장
		int prev = arr[sy][sx];

		// 위쪽↑
		for (int i = sx; i < ex; i++) arr[sy][i] = arr[sy][i + 1];

		// 오른쪽 →
		for (int i = sy; i < ey; i++) arr[i][ex] = arr[i + 1][ex];

		// 아래쪽↓
		for (int i = ex; i > sx; i--) arr[ey][i] = arr[ey][i - 1];

		// 왼쪽 ←
		for (int i = ey; i > sy; i--) arr[i][sx] = arr[i - 1][sx];

		// 저장해둔 값 삽입
		arr[sy + 1][sx] = prev;

	}
}

/*
6 8 1
1 1 1 1 2 2 2 2
1 1 1 1 2 2 2 2
1 1 1 1 2 2 2 2
3 3 3 3 4 4 4 4
3 3 3 3 4 4 4 4
3 3 3 3 4 4 4 4
6 이 숫자가 switch
*/

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int oper;
	while (R--) {
		cin >> oper;

		switch (oper) {
		case 0: break;
		case 1:	flipV();   break; // 상하
		case 2:	flipH();   break; // 좌우
		case 3:	turnCW();  break; // 시계
		case 4: turnCCW(); break;
		case 5: func5();   break; // 4등분한 영역 변경
		case 6: func6();   break;
		case 7: turnSquareCW(2, 3, 2);  break; // 배열 안의 특정 정사각형 구역, 시계
		case 8: turnSquareCCW(2, 3, 2); break;
		case 9: shiftCCW(); break; // 반시계 90도씩 한 칸씩 밀기 
		}
	}

	print();

	return 0;
}