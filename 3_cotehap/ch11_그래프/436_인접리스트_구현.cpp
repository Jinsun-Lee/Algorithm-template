#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

struct nodeInfo { // 노드 정보를 저장할 구조체
	int V; // 노드 번호
	int W; // 가중치
};

// 연결리스트 선언
vector<vector<nodeInfo>> adjList; 

// 인접리스트를 만들고 데이터 채우기
void addEdge(int u, int v, int w) {
	// 무방향 그래프는 양방향으로 간선 정보 추가
	adjList[u].push_back({ v, w });
}

void printAdjList() {
	for (int i = 0; i < adjList.size(); i++) {
		cout << "Node " << i << ":";
		for (const auto& node : adjList[i]) {
			cout << " -> (" << node.V << ", " << node.W << ")";
		}
		cout << endl;
	}
}

int main() {

	// 노드의 개수
	int N = 5;

	// 인접리스트 크기 설정
	adjList.resize(N);

	// 간선 추가 addEdge(u, v, w) 시작, 도착, 가중치
	addEdge(1, 2, 3);
	addEdge(2, 1, 6);
	addEdge(2, 3, 5);
	addEdge(3, 2, 1);
	addEdge(3, 4, 13);
	addEdge(4, 4, 9);
	addEdge(4, 1, 42);

	printAdjList();

	return 0;
}