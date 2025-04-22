# [1주차. DFS](https://cafe.naver.com/dremdeveloper/1364)

### 1. DFS를 구현하는 대표적인 두 가지 방법은 재귀 호출을 이용하는 것과 명시적인 스택(Stack) 자료구조를 사용하는 것입니다. 각 구현 방식의 장단점을 비교 설명해주세요
```
스택(반복문)
장: 메모리 사용 효율적 → 오버플로우 방지
단: 구현 복잡(방문 여부와 같은 상태 추적 로직을 직접 구현해야 함)

재귀함수(함수 호출을 스택처럼 사용할 수 있음)  
장: 직관적 구현
단: 비효율적
```

<br>

### 2. 방향 그래프(Directed Graph)에서 사이클(Cycle) 존재 여부를 판별하기 위해 DFS를 어떻게 활용할 수 있는지 구체적인 알고리즘을 설명해주세요. 
```
* 사이클은 노드들이 연결되어 순환구조가 생기는 것

422p 존재하는 노드들에 대해 방문 여부를 false로 두고 시작한 후
연결될 노드들의 루트를 보고 같은지 확인해서 사이클을 확인할 수 있음
```

<br>

### 3. 재귀를 활용한 DFS에서 가장 최근의 노드로 돌아가는 백트래킹 동작이 어떤 방식으로 동작하는지 하나의 예를 들어 설명해주세요
```
시작 노드를 push
스택에서 노드를 pop

pop한 노드의 방문 확인
방문하지 않았다면 방문 처리

방문한 노드와 인접한 노드를 모두 확인
방문하지 않은 노드를 스택에 push
이때 ABC 순서로 방문처리하고 싶다면 CBA 순서로 push해야 함

반복

스택에서 노드를 pop하면
최근에 스택에 push한 노드
탐색할 노드가 없을 때까지 계속 확인하고
인접한 노드 중 방문할 push하지 않을 뿐임
이 과정에서 스택이 LIFO이기 때문에 깊게 탐색됨
```
```
dfs(int start)일 때, dfs(1)로 시작하면

우선 1번 노드를 방문, 인접한 노드 중 방문하지 않는 노드 확인
아직 dfs(1)을 종료하지 않은 상태에서, dfs(인접한노드)를 호출
dfs(인접한노드)가 종료되면, dfs(1)이 종료되기 때문에 스택의 역할 수행
```

<br>

---

### 풀어볼 문제 https://github.com/Jinsun-Lee/CT_Cotehap/issues/6
- [몸풀기 36번](https://github.com/Jinsun-Lee/CT_Cotehap/blob/master/Chapter11/36.cpp)
- [네트워크](https://github.com/Jinsun-Lee/CT_Cotehap/blob/master/Chapter11/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC.cpp)
- [양과 늑대](https://github.com/Jinsun-Lee/CT_Cotehap/blob/master/Chapter11/%EC%96%91%EA%B3%BC%20%EB%8A%91%EB%8C%80.cpp)
- []()
