#include <iostream>
using namespace std;

int N,M;
int arr[9];

void dfs(int depth){
	if(depth>=M){
		for(int i = 0; i <M; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int start = 1;
	if(depth!=0) start = arr[depth-1];
	for(int i = start; i <=N; i++){
		arr[depth]=i;
		dfs(depth+1);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	dfs(0);
	return 0;
}