# 시뮬레이션
1. [⭐](https://github.com/Jinsun-Lee/Algorithm-template/discussions/36)1_[15686](https://www.acmicpc.net/problem/15686)_치킨배달: [DFS(더 좋음)](https://github.com/Jinsun-Lee/Algorithm-template/blob/master/H8_simulation/1_15686_DFS.cpp)랑 [next_permutation(주의)](https://github.com/Jinsun-Lee/Algorithm-template/blob/master/H8_simulation/1_15686_STL.cpp)로 풀어보기
2. [⭐](https://github.com/Jinsun-Lee/Algorithm-template/discussions/37)2_[18808](https://www.acmicpc.net/problem/18808)_스티커붙이기: 
3. [⭐](https://github.com/Jinsun-Lee/Algorithm-template/discussions/35)⭐⭐3_[15683](https://www.acmicpc.net/problem/15683)_감시: 
4. [⭐](https://github.com/Jinsun-Lee/Algorithm-template/discussions/38)⭐⭐4_[12100](https://www.acmicpc.net/problem/12100)_2048(Easy): 

<br>

```cpp
// N개 중에서 M개 선택 시, 앞에 M개가 0(선택)
vector<bool> mask(N, 1); // 011 → 101 → 110
fill(mask.begin(), mask.begin() + M, 0);
fill(mask.begin(), mask.end() + M - chick.size(), 0); // 동일

do {
    if (mask[i]==0) 동작
} while (next_permutation(mask.begin(), mask.end())); 
```

```cpp

```

```cpp

```

```cpp

```
