#include <iostream>
#include <queue>

using namespace std;

int total, target, now, u, d;

const int MX = 1000002;
int dist[MX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> total >> now >> target >> u >> d;

	fill(dist+1, dist+1 + total, -1); // 1층에서부터 시작해서 1을 더해줌
	dist[now] = 0;

	queue<int> q;
	q.push(now);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : {cur+u, cur-d}) {
			if (nxt <= 0 || nxt > total) continue; // 얘는 0도 포함
			if (dist[nxt] >= 0) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}

	if (dist[target] == -1) cout << "use the stairs";
	else cout << dist[target];

	return 0;
}