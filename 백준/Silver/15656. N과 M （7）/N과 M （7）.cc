#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
const int MX = 8;
bool chk[MX];
int num[MX];
int ans[MX];

void dfs(int depth){
	if(depth>=M){
		for(int i = 0; i <M; i++) cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	// ⭐ 6번에서 수정
	for(int i = 0; i < N; i++){ 
		//if(chk[i]) continue;
		ans[depth]=num[i];
		//chk[i]=1;
		dfs(depth+1);
		//chk[i]=0;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*,"input.txt","r",stdin);
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> num[i];
	sort(num,num+N);
	dfs(0);
	return 0;
}