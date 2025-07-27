#include <iostream>
#include <iomanip>
using namespace std;

#define MX 301
#define endl "\n"

int N,M,R;
int arr[MX][MX];
int tmp[MX][MX];

void print(){
	for(int i = 0; i <N; i++){
		for(int j=0; j <M; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void copy(){
	for(int i = 0; i <N; i++){
		for(int j=0; j <M; j++){
			arr[i][j]=tmp[i][j];
		}
	}
}

void f9(){ // 반시계 90도씩 한 칸씩 밀기 
	int layers = min(N,M) / 2; // 레이어의 수

	for(int k = 0; k < layers; k++) {
		int sy = k,sx = k;
		int ey = N -k -1,ex = M -k -1;	

		// 첫 값 저장
		int prev = arr[sy][sx];

		// 위쪽
		for(int i = sx; i < ex; i++)
			arr[sy][i] = arr[sy][i + 1];

		// 오른쪽
		for(int i = sy; i < ey; i++)
			arr[i][ex] = arr[i + 1][ex];

		// 아래쪽
		for(int i = ex; i > sx; i--)
			arr[ey][i] = arr[ey][i - 1];

		// 왼쪽
		for(int i = ey; i > sy; i--)
			arr[i][sx] = arr[i - 1][sx];

		// 저장해둔 값 삽입
		arr[sy + 1][sx] = prev;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N>>M>>R;
	for(int i = 0; i <N; i++){
		for(int j=0; j <M; j++){
			cin >> arr[i][j];
		}
	}

	while(R--) f9();

	print();

	return 0;
}