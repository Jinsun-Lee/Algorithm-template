# [2주차. 그래프이론, 인접행렬, 인접리스트, DFS, BFS, 트리순회](https://blog.naver.com/PostView.naver?blogId=jhc9639&logNo=222289089015&categoryNo=157&parentCategoryNo=0&viewDate=&currentPage=2&postListTopCurrentPage=1&from=postView&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=2)


### <mark>기본 개념

정점 = vertex = 노드  
간선 = edge = 선  

단방향  
양방향

V, U  
나가는 간선 outdegree  
들어오는 간선 indegree

가중치  
정점과 정점 사이의 비용

트리   
자식과 부모 노드로 이루어진 계층적인 구조  
무방향 그래프의 일종  
사이클이 없는 자료구조 

간선수 = 노드수 -1   
E = V - 1 

두 노드 사이의 경로가 유일무이   
= 어떤 노드까지의 경로가 반드시 있고, 1개  

<br>

<p align="left">
  <img src="https://github.com/user-attachments/assets/fad09e49-af20-4645-b96e-42f8855aa85e" width="200" height="200">
  <img src="https://github.com/user-attachments/assets/cb6d01b3-5183-45dc-88ac-a7f398f839bf" width="200" height="200">
</p>

<br>

깊이  
트리에서의 깊이는 각각의 노드마다 다름   
루트 노드에서 특정 노드까지의 최단 거리  
4번의 깊이는 2  

높이  
루트 노드부터 리프 노드까지의 거리 중 가장 긴 거리  
트리의 높이는 3  
 
레벨  
트리의 레벨은 보통 깊이와 같다고 보면 됨  
1번 노드를 0레벨로 보면, 2번 3번 노드는 1레벨  

서브트리  
트리 내의 하위 집합 = 부분 집합   
5, 6, 7번 노드가 이 트리의 하위 집합  

숲  
트리로 이루어진 집합  

---

### <mark>이진트리, BT, Binary Tree

![Image](https://github.com/user-attachments/assets/2a414ea5-3c51-4eff-a29f-e892da8162b4)

정이진 트리[^정이진]: 자식 노드가 0 또는 2개인 이진 트리  
완전 이진 트리[^완전이진]: 마지막 레벨을 제외하고는 모든 레벨이 꽉 차 있음(왼쪽부터 채움)  
변질 이진 트리[^변질이진]: 자식 노드가 하나밖에 없는 이진 트리(리프 노드 제외)  
포화 이진 트리[^포화이진]: 모든 노드가 꽉 차 있는 이진 트리  
균형 이진 트리[^균형이진]: 모든 노드가 왼쪽 하위 트리와 오른쪽 하위 트리의 높이 차이가 1 이하인 이진 트리  
높이 차이는 하위 트리의 전체 높이를 기준으로 계산  
한쪽에 치우치지 않게 구조 유지 = 삽입, 삭제, 탐색 등의 연산이 O(logN)으로 보장 가능  
레드 블랙 트리 red-black tree는 균형 이진 트리의 한 예

[^정이진]: 정이진 트리, full binary tree  
[^완전이진]: 완전 이진 트리, complete binary tree  
[^변질이진]: 변질 이진 트리 degenerate binary tree  
[^포화이진]: 포화 이진 트리, perfect binary tree   
[^균형이진]: 균형 이진 트리, balanced binary tree   

---

### <mark>이진 탐색 트리, BST, Binary Search Tree

![Image](https://github.com/user-attachments/assets/a76ddf6a-182d-424b-8e74-355e77683eea)  

이진트리의 일종  
<mark>왼쪽 하위 노드에는 노드보다 작은 값 / 오른쪽 하위 노드에는 노드보다 큰 값이 들어 있음</mark>   
이 덕분에 검색에 용이 + 삽입, 삭제, 탐색, 수정 모두 <mark>O(logN)   

근데, 삽입 순서에 따라 영향  
트리의 노드들을 회전해서 균형 잡히게 만듦  
이렇게 발전된 트리가 AVL트리, 레드블랙 트리   
map도 레드 블랙 트리를 기반이라 O(logN)을 보장

---

### <mark>그래프의 구현과 탐색
1. 인접 행렬
2. <mark>인접 리스트

<br>

인접 행렬은 그래프에서 정점과 간선의 관계를 bool 타입의 행렬로 

<p align="left">
  <img src="https://github.com/user-attachments/assets/8c297abb-832f-4baf-ae95-a7f87ec24da3" width="200" height="200">
  <img src="https://github.com/user-attachments/assets/d82b00b8-3b6d-45d4-882f-f5f30e5c3dc7" width="200" height="200">
  <img src="https://github.com/user-attachments/assets/b3fa92aa-9d95-422c-be72-7194b2ec9c11" width="200" height="200">
</p>

<br>

<details><summary>Q1. 3번 노드에서 5번 노드로 가는 단방향/양방향 경로가 있을 때 이를 인접행렬로 표현</summary>

```cpp
a[3][5] = 1;
```
```cpp
a[3][5] = 1;
a[5][3] = 1;
```
</details>

<br>

<details><summary>Q2. 정점의 갯수가 20개인 그래프를 인접행렬로 표현할 때, 메모리를 최소로 써서 배열을 선언</summary>

```cpp
bool a[20][20];
```
</details>

<br>

정점은 0 ~ 9까지 10개  
양방향 12 13 34 경로가 있고  
0번부터 방문 안 한 노드를 찾고, 해당 노드부터 방문, 연결된 노드들을 이어서 방문 후 출력하는 재귀함수(방문한 정점은 다시 방문하지 않음)  
 
<details><summary>Q3. 인접행렬로 정답 코드</summary>

```cpp
#include <iostream>
using namespace std;

const int V = 10;
bool a[V][V], vis[V];

void go(int from) {
    vis[from] = 1;
    cout << from << "\n";
    for (int to = 0; to < V; ++to) {
        if (!vis[to]) continue;
        if (a[from][to]) go(to); //
    }
}

int main() {
    a[1][2] = 1; a[2][1] = 1;
    a[1][3] = 1; a[3][1] = 1;
    a[3][4] = 1; a[4][3] = 1;

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (a[i][j] && vis[i]==0) go(i);  //
        }
    }
    
    return 0;
}
```
</details>

<br>

<details><summary>Q4. 인접 리스트로 위의 보라색 그래프 출력</summary>

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int V = 4;
vector<int> adj[V];

int main() {
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(0);
    adj[2].push_back(1);

    adj[3].push_back(0); 

    for (int i = 0; i < V; ++i) {
        if (adj[i].size()>0) cout << i << ": ";

        // 방법 2개 숙지 
        // for (int j = 0; j < adj[i].size(); ++j) cout << adj[i][j] << " ";
        for (int j : adj[i]) cout << j << " ";

        if (adj[i].size() > 0) cout << "\n";
    }
    
    return 0;
}
```
</details>

<br>

<details><summary>Q5. 인접리스트로 정답 코드</summary>

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int V = 10;
vector<int> adj[V];
bool visited[V];

void go(int from) {
    visited[from] = 1;
    cout << from << "\n";

    for (int to : adj[from]) { // 이렇게 바꿔
        if (!visited[to]) go(to); 
    }
}

int main() {
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3); 
    adj[3].push_back(1);

    adj[3].push_back(4); 
    adj[4].push_back(3);

    for (int i = 0; i < V; ++i) {
        if (adj[i].size() && !visited[i]) go(i); //
    }
    return 0;
}
```
</details>

<br>

### 인접행렬과 인접리스트의 차이

공간복잡도
```cpp
// 인접행렬 O(V^2)
bool adj[V][V];

// 인접리스트 O(V + E)
vector<int> adj[V]; 
```

시간복잡도 : 간선 한개 찾기
```cpp
// 인접행렬 O(1)
for(int i = 0;i < V; i++){
    for(int j = 0; j < V; j++){
        if(a[i][j]){ 
        }
    }
}

// 인접리스트 O(V) 
for(int j = 0; j < adj[i].size(); j++){
    cout << adj[i][j] << " ";
} 
```

시간복잡도 : 모든 간선찾기
 - 인접행렬 : O(V^2)
 - 인접리스트 :  O(V + E)  

<br>

![Image](https://github.com/user-attachments/assets/4b4a475f-d394-4a5b-9478-e43de36eb7bc)

인접리스트 = 그래프가 희소 sparse   
인접행렬은 대부분의 요소가 0인데도 2차원 배열을 만들어야 해서, 인접행렬이 메모리를 더 많이 씀  
<mark>보통 코테에는 희소 그래프가 多 = 인접리스트 써<mark>

인접행렬 = 그래프가 조밀 dense   
어차피 다 연결되어 있어서 메모리적 효율은 동일  
<mark> i에서 정점 j까지의 간선이 있는지 확인하는 속도는 인접행렬이 더 빠름<mark>  

<br>

---

### <mark>맵과 방향벡터  
인접행렬이나 인접리스트로 문제를 줄 수도 있지만, 맵으로 주기도 함  
이때 이 맵은 인접행렬이 절대 아님

<br>

#### 방향 탐색

<details><summary>Q6. {0,0} 좌표에서 dy, dx를 만들어 4방향/8방향을 탐색하며 좌표 출력</summary>

```cpp
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int y = 0, x = 0;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        cout << ny << " " << nx << "\n";
    }
    return 0;
}
```

```cpp
const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    for (int i = 0; i < 8; ++i) {
        int ny = y + dy[i];
```
</details>


<br>

<br>

아래 입력처럼 3*3 맵이 주어질 때, 출발 지점인 {0, 0}은 무조건 1임을 보장한다

```
1 0 1
1 0 1
0 1 1
```

<details><summary>Q7. 맵에서 0은 벽, 1은 빈 공간일 때 방문한 곳을 다시 방문하지 않고, 4방향으로 이동해 방문한 좌표를 출력해라</summary>

```cpp
const int N = 3;
bool map[N][N], visited[N][N];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
    visited[y][x] = 1;
    cout << y << ", " << x << "\n";

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
        if (!map[ny][nx] || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    dfs(0, 0);
    return 0;
}
```
</details>

<br><br>

플러드필로 연결되었는지 아닌지     
컴포넌트 = 그룹을 지을 수 있다  

<br>

--- 

### <mark>DFS
```cpp
DFS(u, adj)
    u.visited = true
    for each v ∈ adj[u]
        if v.visited == false
            DFS(v, adj)
```


<br>

![Image](https://github.com/user-attachments/assets/ccc4525f-6443-49da-bed5-29b1801b5cf0)

<details><summary>Q8. 위 방문을 DFS로 구현하면 방문 순서는?</summary>

1 2 4 5 3이 나와야 해
```cpp
#include <iostream>
#include <vector>
using namespace std;

const int n = 6;
vector<int> adj[n];
bool visited[n];

void dfs(int from) {
    cout << from << " ";

    for (int to : adj[from]) {
        if (visited[to]) continue;
        visited[to] = 1;
        dfs(to);
    }

    cout << from << "로부터 시작한 함수 종료\n";
    return; 
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    
    visited[1] = 1;
    dfs(1);

    return 0;
}
```
</details>


<br>

종화는 방구쟁이  
방귀를 뀌면 4방향으로 퍼지며, 연결된 육지는 전부 오염된다  
바다로는 방구가 퍼지지 않는다  
육지는 1, 바다는 0이다   
```
1 <= N <= 100
1 <= M <= 100 
```
```
5 5
1 0 1 0 1
1 1 0 0 1
0 0 0 1 1
0 0 0 1 1
0 1 0 0 0
```
<details><summary>Q9. 몇 번 방구를 뀌어야 모든 육지를 오염시킬 수 있을까?</summary>

4가 잘 나와야 함
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

const int MX = 101;
int N, M, vis[MX][MX];
bool map[MX][MX];

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({ y, x });
    vis[y][x] = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
      
        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
            if (map[ny][nx]==0 || vis[ny][nx]) continue;
            vis[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cin >> map[i][j];
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // if (!map[i][j] || visited[i][j]) continue;
            if (map[i][j] == 1 && vis[i][j] == 0) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt;
    return 0;
}
```
```cpp
const int MX = 102;
int N, M;
bool map[MX][MX];
bool visited[MX][MX];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int ny, nx;

void dfs(int y, int x) {
    for (int i = 0; i < 4; ++i) {
        ny = y + dy[i];
        nx = x + dx[i];

        if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
        if (map[ny][nx] == 0 || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
    return;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cin >> map[i][j];
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!map[i][j] || visited[i][j]) continue;
            visited[i][j] = 1;
            dfs(i, j);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
```
</details>

<br>

---

### <mark>BFS, Breadth First Search
다음 깊이의 정점으로 이동하기 전 현재 깊이의 모든 정점을 탐색  
같은 가중치를 가진 그래프에서 최단 거리 알고리즘으로 쓰임  

```cpp
BFS(G, u)
    u.visited = true
    u.dist = 1
    q.push(u);

    while(q.size()) 
        u = q.front() 
        q.pop()

        for each v ∈ G.Adj[u]
            if v.visited == false
                v.visited = true
                v.dist = u.dist+ 1
                q.push(v)
```

<br>

![Image](https://github.com/user-attachments/assets/b97e2041-670c-4808-acfd-98bec1176622)

<br>

<details><summary>Q10. 10번정점으로부터 24번 정점까지의 최단거리는 얼마일까?</summary>

3이 출력되면 맞아
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100];
int dist[100];
int nodeList[] = { 10, 12, 14, 16, 18, 20, 22, 24 };

void bfs(int from){
    queue<int> q;
    q.push(from);
    dist[from]=1;

    while (!q.empty()) { // q.size()도 오케
        int cur = q.front(); q.pop();

        for (int to : adj[cur]) {
            if (dist[to]) continue;
            dist[to] = dist[cur]+1;
            q.push(to);
        }
    }
}

int main() {
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);
    adj[12].push_back(18);
    adj[12].push_back(20);
    adj[20].push_back(22);
    adj[20].push_back(24);

    bfs(10);

    for (int i : nodeList) {
        cout << i << ": " << vis[i] << "\n";
    }

    cout << *max_element(vis, vis + 100);
    // cout << "10번으로부터 24번까지 최단거리는 : " << dist[24] - 1 << '\n';

    return 0;
}
```
</details>


<br>

승철이의 당근마켓  
승철이가 좋아하는 당근차는 한 칸 움직일 때마다 당근을 1개 소비  
차는 육지로만 상하좌우 이동 가능, 1은 육지, 0은 바다

입력은 N, M(1 <= N, M <= 100)  
승원이의 위치 y, x  
도착지점 좌표 y, x  
```
5 5
0 0
4 4
1 0 1 0 1
1 1 1 0 1
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1
```

<details><summary>Q11. 도착 지점까지 갈 때 필요한 최소한의 당근 수는?</summary>


9가 나와야 해

<details><summary>내 코드</summary>

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int y, x;
};

const int MX = 101;
bool map[MX][MX];
int dist[MX][MX];

int N, M, sy, sx, ey, ex;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int ny, nx;

void bfs(int y, int x){
    queue<Node> q;
    q.push({y, x});
    dist[sy][sx] = 1;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            ny = cur.y + dy[i];
            nx = cur.x + dx[i];

            if (ny == ey && nx == ex) {
                cout << dist[cur.y][cur.x] + 1;
                return;
            }

            if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
            if (!map[ny][nx] || dist[ny][nx]) continue;
            dist[ny][nx]= dist[cur.y][cur.x] + 1;
            q.push({ ny, nx });
        }
    }
}

int main() {
    cin >> N >> M >> sy >> sx >> ey >> ex;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cin >> map[i][j];
    }

    bfs(sy, sx); 
    return 0;
}
```
```cpp
int main() {
    cin >> N >> M >> sy >> sx >> ey >> ex;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cin >> map[i][j];
    }

    queue<Node> q;
    q.push({ sy, sx });
    dist[sy][sx] = 1;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            ny = cur.y + dy[i];
            nx = cur.x + dx[i];

            if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
            if (!map[ny][nx] || dist[ny][nx]) continue;
            dist[ny][nx] = dist[cur.y][cur.x] + 1;
            q.push({ ny, nx });
        }
    }

    cout << dist[ey][ex]; // 최단 거리
    return 0;
}
```
</details>


```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <utility> // ⭐pair
#include <tuple>   // ⭐tie
using namespace std;

const int MX = 101;
bool map[MX][MX];
int dist[MX][MX];

int N, M, sy, sx, ey, ex;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int y, x, ny, nx;

int main() {
    cin >> N >> M >> sy >> sx >> ey >> ex;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cin >> map[i][j];
    }

    queue<pair<int, int>> q; //⭐ Node 대체
    q.push({ sy, sx });
    dist[sy][sx] = 1;

    while (!q.empty()) {
        tie(y, x) = q.front(); q.pop(); //⭐ tie 사용
        for (int i = 0; i < 4; ++i) {
            ny = y + dy[i]; //⭐ cur.y 대신 y
            nx = x + dx[i];

            if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
            if (!map[ny][nx] || dist[ny][nx]) continue;
            dist[ny][nx] = dist[y][x] + 1; //⭐ cur.y 대신 y
            q.push({ ny, nx });
        }
    }

    cout << dist[ey][ex];
    return 0;
}
```
</details>

<br>

---

### DFS와 BFS 비교
둘 다 시간복잡도는 동일  
인접리스트면 O(V+E)  
인접행렬이면 O(V^2)  

DFS  
메모리 덜 씀  
절단점 등 구할 수 있음  
완탐에서 많이 씀  

BFS  
메모리 더 씀  
가중치 같은 그래프 내에서 최단 거리 구할 수 있음  

---

### <mark>트리 순회 Tree traversal  
트리 구조에서 각각의 노드를 정확히 한 번만, 체계적인 방법으로 방문하는 과정  
노드를 방문하는 순서에 따라 후위순회, 전위순회, 중위순회, 레벨 순회  

<br>

후위 순회 postorder traversal  
자식들 노드를 방문하고 자신의 노드 방문
```cpp
postorder( node )
    if (node.visited == false) 
        postorder( node->left ) 
        postorder( node->right )
        node.visited = true
```

<br>

전위 순회 preorder traversal  
자신의 노드를 방문하고, 그 다음 노드들을 방문  
DFS를 생각하면 됨
```cpp
preorder( node )
    if (node.visited == false)
        node.visited = true
        preorder( node->left )
        preorder( node->right )
```

<br>

중위 순회 inorder traversal  
왼쪽 노드를 먼저 방문, 자신의 노드 방문, 오른쪽 노드 방문
```cpp
inorder( node )
    if (node.visited == false) 
        inorder( node->left )
        node.visited = true
        inorder( node->right )
```

<br>

레벨순회 level traversal   
BFS를 생각하면 됨

<br>

---

![Image](https://github.com/user-attachments/assets/3887c304-7e73-4487-b096-bd862167fbc0)

<br>


<details><summary>Q12. 위와 같은 그래프가 주어졌을 때 각각의 함수를 구현하고, 방문한 노드를 출력하도록 구현해라</summary>

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1004];
int visited[1004];

void postOrder(int here) {
    if (visited[here] == false) {
        if (adj[here].size() == 1) postOrder(adj[here][0]); // left adj[here][0]인 것 주의
        if (adj[here].size() == 2) { // right
            postOrder(adj[here][0]);
            postOrder(adj[here][1]);
        }
        visited[here] = 1;
        cout << here << " ";
    }
}

void preOrder(int here) {
    if (visited[here] == false) {
        visited[here] = 1;
        cout << here << " ";

        if (adj[here].size() == 1) postOrder(adj[here][0]);
        if (adj[here].size() == 2) {
            postOrder(adj[here][0]);
            postOrder(adj[here][1]);
        }
    }
}

void inOrder(int here) {
    if (visited[here] == false) {
        if (adj[here].size() == 1) {
            inOrder(adj[here][0]);
            visited[here] = 1; // 위치
            cout << here << " ";
        }
        else if (adj[here].size() == 2) { // else if 주의
            inOrder(adj[here][0]);

            visited[here] = 1; // 따로 있어야 해
            cout << here << " ";

            inOrder(adj[here][1]);
        }
        else {
            visited[here] = 1; // 따로 있어야 해
            cout << here << " ";
        }
    }
}

int main() {
    int root = 1;
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    // 4 5 2 3 1
    cout << "후위순회 \n"; postOrder(root);
    memset(visited, 0, sizeof(visited));

    // 1 2 4 5 3
    cout << "\n\n전위순회 \n"; preOrder(root);
    memset(visited, 0, sizeof(visited));

    // 4 2 5 1 3
    cout << "\n\n중위순회 \n"; inOrder(root);

    return 0;
}
```
</details>

<br>

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1004];
int visited[1004];

void postOrder(int here) {

}

void preOrder(int here) { 

}

void inOrder(int here) {

}

int main() {
    int root = 1;
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    // 4 5 2 3 1
    cout << "후위순회 \n"; postOrder(root);
    memset(visited, 0, sizeof(visited));

    // 1 2 4 5 3
    cout << "\n\n전위순회 \n"; preOrder(root);
    memset(visited, 0, sizeof(visited));

    // 4 2 5 1 3
    cout << "\n\n중위순회 \n"; inOrder(root);

    return 0;
}
```

---

### 정리
![Image](https://github.com/user-attachments/assets/d18fdd77-8256-4a8e-8d30-796c8d605821)