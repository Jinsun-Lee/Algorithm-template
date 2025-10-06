#include <iostream>
#include <queue>
using namespace std;

const int MX = 100002;
int dist[MX];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

    int now, target;
	cin >> now >> target;

	fill(dist, dist + MX, -1);
	dist[now] = 0;

	queue<int> q;
	q.push(now);

	while (dist[target] == -1) {
		int cur = q.front(); q.pop();

		for (int nxt : {cur - 1, cur + 1, cur * 2}) {
			if (nxt <0 || nxt > MX-2) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}

	cout << dist[target];
	return 0;
}
