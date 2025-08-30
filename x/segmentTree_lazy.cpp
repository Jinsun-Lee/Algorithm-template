#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr; // 원본 배열
vector<int> tree; // 트리 배열
vector<int> lazy; // 지연 업데이트 배열
int n;

void build(int node, int start, int end) { // 트리 빌드
    if (start == end) tree[node] = arr[start]; // 시작점과 끝점이 같다면 해당 인덱스를 의미하므로, 그 지점에 배열값 저장.
		
    else { // 이 부분은 트리의 다른 함수에도 비슷하게 적용됨
        int mid = (start + end) / 2; // 중간점 계산
        build(2 * node, start, mid); // 시작점부터 중간점까지 서브트리 빌드
        build(2 * node + 1, mid + 1, end); // 중간점 + 1 부터 마지막 지점까지 서브트리 빌드
        tree[node] = tree[2 * node] + tree[2 * node + 1]; // 서브트리의 루트 부분은 그 하위 리프노드의 합을 의미하므로, 두 서브트리를 합쳐서 구간합 노드 생성
    }
}

void push_down(int node, int start, int end) { // 지연된 업데이트를 자식 노드로 내리는 함수
    if (lazy[node] != 0) { // 만약 지연된 업데이트 값이 있다면 업데이트를 수행
        tree[node] += (end - start + 1) * lazy[node]; // 현재 노드의 리프 노드 수만큼 업데이트를 해야 하므로, 하위 리프 노드 수 * 지연값을 현재 노드에 더해줌
		
        if (start != end) { // 만약 현재 노드가 리프 노드가 아니라면
            lazy[2 * node] += lazy[node]; // 하위 노드 2개에 각각 지연값을 전파
            lazy[2 * node + 1] += lazy[node];
        }
		
        lazy[node] = 0; // 업데이트가 완료됐으므로, 지연값을 없앤다.
    }
}

int query_range(int node, int start, int end, int l, int r) { // 트리에서 구간합을 구하는 함수
    push_down(node, start, end); // 먼저, 현재 노드에 지연된 업데이트 값이 있다면, 계산 후 하위 두개 노드로 전파
    
	if (start > end || r < start || end < l) return 0; // 현재 구간에 필요한 계산값이 없다면 리턴

    if (l <= start && end <= r) return tree[node]; // 현재 구간이 원하는 구간과 일치한다면 구간합 반환
        
    // 현재 구간이 원하는 구간과 완전히 일치하지 않는다면 구간 나누기 수행
    int mid = (start + end) / 2; // 트리에서 자주 보이는 구조. 중간점을 구한 후, 시작점 ~ 중간점, 중간점+1 ~ 마지막 지점으로 나눠서 각각 재귀로 수행 
    int p1 = query_range(2 * node, start, mid, l, r);
    int p2 = query_range(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2; // 두 서브트리에서 구한 구간합을 더해서 리턴
}

void update(int node, int start, int end, int idx, int val) { // 이 함수는 지연 업데이트가 적용되지 않은 트리에서 사용됨. 
    // 지연 업데이트가 적용된 트리에서는 update_range 함수에 start와 end에 같은 값을 사용하면 되므로, 이 함수는 일반적인 segment tree에서만 사용한다.

    if (start == end) { // 시작점과 끝점이 같다면, 업데이트할 리프 노드를 의미
        arr[idx] = val; // 원본 배열과 트리 배열을 각각 업데이트
        tree[node] = val;
    }
		
    else if (idx < start || end < idx) return; // 현재 트리에 목표 인덱스가 없다면 리턴
		
    else {
        int mid = (start + end) / 2; // 현재 트리에 목표 인덱스가 있다면, 목표 인덱스가 나올 때까지 재귀
        
		if (start <= idx && idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
		
        tree[node] = tree[2 * node] + tree[2 * node + 1]; // 구간 합 노드 업데이트
    }
}

void update_range(int node, int start, int end, int l, int r, int val) { // 지연 업데이트 적용 시 사용되는 업데이트 함수
    push_down(node, start, end); // 업데이트 전 먼저 현재 노드 값 업데이트 후 하위 노드로 지연된 업데이트 값 전파
    
	if (start > end || start > r || end < l) return; // 범위를 벗어나면 리턴
    
    if (l <= start && end <= r) { // 만약 원하는 구간과 현재 구간이 일치한다면,
        tree[node] =+ (end - start + 1) * val; // 현재 노드 업데이트
		
        if (start != end) { // 만약 현재 노드가 리프 노드가 아니면,
            lazy[2 * node] += val; // 하위 두 개 노드의 lazy 값만 업데이트
            lazy[2 * node + 1] += val;
        }
        return; // 업데이트한 현재 구간이 일치하므로, 함수 종료
    }
	
    int mid = (start + end) / 2; // 원하는 구간과 일치하지 않는다면,
    update_range(2 * node, start, mid, l, r, val); // 하위 두개 노드로 나눠서 재귀 실행
    update_range(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1]; // 구간합 업데이트
}

void debuging() {
    cout << "arr : ";
    for (int x : arr) cout << x << ' ';
    cout << '\n';

    cout << "tree : ";
    for (int x : tree) cout << x << ' ';
    cout << '\n';

    cout << "lazy : ";
    for (int x : lazy) cout << x << ' ';
    cout << '\n';
}

int main() {
    cin >> n;
	
    arr.resize(n);
    tree.resize(n * 4); // 트리 노드 배열 크기는 일반적으로 원본 배열 크기 * 4
    lazy.resize(n * 4, 0); // 지연 업데이트 배열 크기 = 트리 노드 배열 크기
	
    for (int i = 0; i < n; i++) arr[i] = i;

    build(1, 0, n - 1);
	
    debuging();
    
    cout << query_range(1, 0, n - 1, 1, 3) << '\n'; // 현재 트리 방식은 1-base index 방식이므로, 시작 노드에 1을 넣어줄 것 끝 지점은 원본 배열 길이 - 1
 
    update_range(1, 0, n - 1, 2, 8, 3);

    debuging();

    update(1, 0, n - 1, 2, 1);

    debuging();

    update(1, 0, n - 1, 5, 9);

    debuging();

    cout << query_range(1, 0, n - 1, 1, 3) << '\n';

    debuging();

    cout << query_range(1, 0, n - 1, 4, 9) << '\n';

    debuging();
}
