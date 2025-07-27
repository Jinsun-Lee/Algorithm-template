# [1주차. 시간복잡도, 빅오표기법, 공간복잡도, 누적합, 구현](https://blog.naver.com/PostView.naver?blogId=jhc9639&logNo=222283814653&categoryNo=157&parentCategoryNo=0&viewDate=&currentPage=2&postListTopCurrentPage=1&from=postView)
1. [코드에서 시간복잡도 분석](#o1), Q1 ~ Q6  
  n! > 2<sup>n</sup> > n<sup>2</sup> > nlogn > n > logn > 1   
  재귀함수에서의 메인로직은 재귀 호출이 없어야 함  
  재귀함수의 시간복잡도 = 메인로직 * 반복 횟수
2. [자료구조의 시간복잡도](#자료구조의-시간복잡도)   
  Q7. `배열, 벡터, 스택, 큐, 연결리스트, 맵`의 `참조, 탐색, 삽입, 삭제`
3. [공간복잡도](#3-공간복잡도)에서 최대 범위랑 메모리 제한  
  `1<= N <= 1,000,000`면 N의 범위는 100만으로 `int N[1000000];`  
  `512MB의 메모리 제한`일 때, `int a[128,000,000];` 선언 가능
4. [누적합](#4-누적합)  
  `구간`에 대한 `쿼리`가 나온다면 트리나 누적합  
  그 구간 안에 있는 요소들이 변하지 않는 정적 요소라면 누적합 이용  
  [Q8.승철이의 뇌 문제](#q8-승철이의-뇌-문제)  
  신입사원, 슈퍼마리오 등 [추가 문제](https://github.com/Jinsun-Lee/Algorithm-template/discussions/28#discussioncomment-12961219)

<br>

---

<br>

# 1. 시간 복잡도  
어떠한 알고리즘이 실행되는데 걸리는 시간   
어떠한 알고리즘이 주어진 `입력 크기를 기반으로` 주요 로직의 반복 횟수를 중점으로 측정   

<br>

# 2. 빅오 표기법
복잡도에 `가장 영향을 많이 끼치는 항`의 상수인자를 빼고 나머지 항을 없애서 복잡도를 나타내는 표기법  
⭐n! > 2<sup>n</sup> > n<sup>2</sup> > nlogn > n > logn > 1

<br>

이 코드의 시간복잡도는 10n<sup>2</sup>+n  
시간 복잡도를 빅오 표기법으로 표현하면 O(n<sup>2</sup>)
```cpp
for(int i = 0; i < 10; i++){
	for(int j =0; j < n; j++){
		for(int k = 0; k < n; k++){
			if(true) cout << k << '\n';
		}
	}
}

for(int i = 0; i < n; i++){
	if(true) cout << i << '\n'; 
}
```

<br>

<div align="right">

[목차🠕](#1주차-시간복잡도-빅오표기법-공간복잡도-누적합-구현)

</div>

## ⭐O(1)
- 입출력: cin, cout, scanf, printf
- 연산: 곱하기, 나누기, 나머지 등
- 간단한 비교 `if (a[2]==2)`
- 배열의 인덱스 참조 `b=a[2]`

<br>

<details><summary>⭐Q1. 시간복잡도는?</summary>

O(n<sup>2</sup>)

외부 루프 i는 0 ~ n-1 총 n번 반복  
내부 루프 j는 0 ~ i-1까지, i에 따라 반복 횟수가 달라짐  
i=0  
∑   i = 0+1+2+⋯+(n−1) = n(n−1)/2  
n−1   

</details>

```cpp
#include<bits/stdc++.h>
using namespace std; 

int main(){
	int n; cin >> n; 
	int a = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			a += i + j; 
		}
	}

	cout << a << '\n';   
	return 0;
} 
```

<br>

<details><summary>⭐Q2. 시간복잡도는?</summary>

O(N + M)
</details>

```cpp
int N, M;

void solve(int N, int M){
	int a = 1; 

	for (int i = 0; i < N; i++) {
		a *= i;  
	}

	for (int j = 0; j < M; j++) {
		a *= j;   
	}

	cout << a << "\n"; 
}

int main(){
	cin >> N >> M; 
	solve(N, M);    
	return 0;
}
```

<br>

<details><summary>⭐Q3. 시간복잡도는?</summary>

O(n)
</details>

```cpp
int n, a[1004], cnt;

int go(int l, int r){ 
	if(l == r) return a[l];  
	int mid = (l + r) / 2; 
	int sum = go(l, mid) + go(mid + 1, r); 
	return sum;
}

int main(){ // 입력 10, 출력 45
	cin >> n; 

	for(int i = 1; i <= n; i++){
		a[i - 1] = i; 
	}

	int sum = go(0, n - 1);
	cout << sum << '\n';  
    return 0;
} 
```

<br>

<details><summary>⭐Q4. 시간복잡도는?</summary>

O(logN)   
N → N/2 → N/4 → ... → 1
</details>

```cpp
int N;

void solve(int N){
	int a = 0, i = N;

	while (i > 0) {
		a += i;
		i /= 2;
	} 

	cout << a << '\n';
}

int main(){
	cin >> N; 
	solve(N);    
	return 0;
} 
```

<br>

<details><summary>⭐Q5. 시간복잡도는?</summary>

O(3ⁿ)

재귀 함수 solve(N)은 입력값 N에 대해 3번씩 solve(N-1)을 호출  
3-진 트리 형태로 확장되며, 깊이는 N  

<br>

</details>

<details><summary>⭐Q6. 재귀함수에서의 메인로직은?</summary>

```cpp
for(int i = 0; i < 3; i++){
    solve(N - 1);
} 
```

로직1 : 주어진 N에 대해 solve(N - 1)을 3번 재귀 호출  
로직2 : 각 호출마다 cnt를 증가시키고 출력  

여기서 메인로직은 재귀적으로 호출되는 함수 부분  
⭐그러나, `재귀함수에서는 재귀 호출이 없어야 함`  
그래서 로직 2가 메인로직(로직1을 빼고 시간 복잡도가 젤 큼)  

재귀함수의 시간복잡도   
= 메인로직 * 반복 횟수  
= O(1)　　* 3<sup>n</sup>  

<br>

</details>

```cpp
int N, cnt;

void solve(int N){
	cnt++;
	cout << cnt << '\n';

	if(N == 0) return;

	for(int i = 0; i < 3; i++){
		solve(N - 1);
	} 

	return;
}

int main(){
	cin >> N; 
	solve(N);    
	return 0;
} 
```

<br><br>

<div align="right">

[목차🠕](#1주차-시간복잡도-빅오표기법-공간복잡도-누적합-구현)

</div>

## 자료구조의 시간복잡도

정적 배열은 삭제 연산이 자주 일어나지 않음  
배열에서 해당 요소를 삭제했을 때 `a[k]=-1`과 같이 표현하는 것이 일반적

<br>

<details>
<summary>⭐Q7-1. 배열의 참조, 탐색</summary>

- 참조: O(1)
- 탐색: O(n) 

<br>

</details>

<details><summary>⭐Q7-2. 벡터의 참조, 탐색, 삽입, 삭제</summary>

- 참조: O(1)
- 탐색: O(n)
- 앞뒤 삽입/삭제: O(1)
- 중간 삽입/삭제: O(n)

<br>

</details>

<details><summary>⭐Q7-3. 스택의 참조, 탐색, 삽입, 삭제</summary>

- 가장 앞부분 참조: O(1)
- n번째 참조: O(n)
- 탐색: O(n)
- 삽입/삭제(n번째 제외): O(1)

<br>

</details>

<details><summary>⭐Q7-4. 큐의 참조, 탐색, 삽입, 삭제</summary>

- `스택이랑 동일`
- 가장 앞부분 참조: O(1)
- n번째 참조: O(n)
- 탐색: O(n)
- 삽입/삭제(n번째 제외): O(1)

<br>

</details>

<details><summary>⭐Q7-5. 연결리스트의 참조, 탐색, 삽입, 삭제</summary>

- 참조: O(n)
- 탐색: O(n)
- 삽입/삭제: O(1)

<br>

</details>

<details><summary>⭐Q7-6. 맵의 참조, 탐색, 삽입, 삭제</summary>

- 참조: O(logn)
- 탐색: O(logn)
- 삽입/삭제: O(logn)

<br>

</details>

<details><summary>⭐Q7. 어떠한 요소들의 모음에서 k번째 요소를 계속해서 참조해야하는 로직에 적합한 자료구조는?</summary>

배열

<br>

</details>

<br><br>

<div align="right">

[목차🠕](#1주차-시간복잡도-빅오표기법-공간복잡도-누적합-구현)

</div>

# 3. 공간복잡도
입력크기에 대해 어떠한 알고리즘이 실행되는데 필요한 메모리 공간의 양

`3-1. 최대 범위`  
보통 최대 범위를 기반으로 배열을 미리 만들곤 함  
문제에서 N (1<= N <= 1,000,000)이라고 하면 N의 최대 범위는 100만
```cpp
int N[1000000];
```

<br>

`3-2. 메모리 제한`  
512MB의 메모리 제한일 때  
512,000,000 바이트이니까 `int a[128,000,000];` 선언 가능

<br><br>

<div align="right">

[목차🠕](#1주차-시간복잡도-빅오표기법-공간복잡도-누적합-구현)

</div>

# 4. 누적합
어떠한 배열을 기반으로 앞에서부터 요소들의 누적된 합을 저장   

`구간`에 대한 `쿼리`가 나온다면 트리나 누적합을 사용   
0번째 요소부터 3번째 요소까지 전부 더해 → 누적합 배열 3번째 요소 이용  

![image](https://github.com/user-attachments/assets/77b9211f-3c54-413a-bb86-a24aca09e4be)  
앞에서부터 더하는 prefix sum, 뒤에서부터 더하는 suffix sum(코테에선 X)

트리는 세그먼트, 펜윅트리    
그 구간 안에 있는 요소들이 변하지 않는 정적 요소라면 누적합 이용

<br>

<div align="right">

[목차🠕](#1주차-시간복잡도-빅오표기법-공간복잡도-누적합-구현)

</div>

#### Q8. 승철이의 뇌 문제
승철이는 뇌를 잃어버렸다. 학교에 갔더니 선생님이 자연수로 이루어진 N개의 카드를 주며 M개의 질문을 던진다. 그 질문은 나열한 카드 중 A번째부터 B번째까지의 합을 구하는 것이다. 뇌를 잃어버렸기 때문에 승철이는 이 문제를 풀 수 없다. 문제를 풀 수 있는 프로그램을 작성해보자.  
```
1 <= N <= 100,000
1 <= M <= 100,000
1 <= A <= B <= N
```

<br>

입력  
수의 개수 N, 합을 구해야 하는 횟수 M, 그 이후 N개의 수가 주어진다. 수는 100 이하의 자연수. 그 이후 M개의 줄에는 합을 구해야 하는 구간 A, B가 주어진다. 
```
8 3
1 2 3 4 5 6 7 8
1 4
1 5
3 5
```

<br>

출력  
M개의 줄에 A부터 B까지의 합을 구하라. 
```
10
15
12
```

<br>

<details><summary>(무식) 승철이의 뇌 코드</summary>

아래 코드는 시간복잡도는 O(10만 * 10만)이며,  
A와 B가 주어졌을 때 한 연산당 시간복잡도는 O(10만)
```cpp
#include<bits/stdc++.h>
using namespace std;

int a[100004], b, c, psum[100004], n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i < m; i++) {
        cin >> b >> c;

        int sum = 0;
        for (int j = b; j <= c; j++) sum += a[j];
        cout << sum << '\n';
    }
    return 0;
}
```
</details>

<br>

<details><summary>(누적합) 승철이의 뇌 코드</summary>

이렇게 빼기만 하면 A부터 B까지를 O(1)
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001], psum[100001], a, b;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i - 1];
    }

    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        cout << psum[b] - psum[a-1] << "\n";
    }
    
    return 0;
}
```
</details>

<br><br>

<div align="right">

[목차🠕](#1주차-시간복잡도-빅오표기법-공간복잡도-누적합-구현)

</div>
