# [세그먼트 트리](https://github.com/Jinsun-Lee/algorithm-study/discussions/64)
- [x] [11659. 구간 합 구하기 4](https://www.acmicpc.net/problem/11659): 그냥 누적합
- [x] [2042. 구간 합 구하기](https://www.acmicpc.net/problem/2042): 풀이 방법 많아서 바이블
    - [x] 1. [Top - Down Segment Tree](https://github.com/Jinsun-Lee/algorithm-study/blob/master/Z26_ETC/_segmentTree/1_2042_%ED%83%91%EB%8B%A4%EC%9A%B4_1%EA%B8%B0%EB%B0%98_diff.cpp): 탑다운  / <mark>1기반 / diff 이용, 내려가면서 val만큼 증가</mark>
    - [x] 2. [Top - Down Segment Tree](https://github.com/Jinsun-Lee/algorithm-study/blob/master/Z26_ETC/_segmentTree/2_2042_%ED%83%91%EB%8B%A4%EC%9A%B4_0%EA%B8%B0%EB%B0%98_diff.cpp): 탑다운 / <mark>0기반</mark> / 위와 동일
    - [x] 3. [Top - Down Segment Tree](https://github.com/Jinsun-Lee/algorithm-study/blob/master/Z26_ETC/_segmentTree/3_2042_%ED%83%91%EB%8B%A4%EC%9A%B4_0%EA%B8%B0%EB%B0%98_%EC%83%88%EA%B0%92%EB%8C%80%EC%9E%85.cpp): 탑다운 / 0기반 / 새로운값, <mark>먼저 내려간 다음에 값 바꾸고 올라가면서 합 다시 구함</mark>
    - [x] 4. [Dynamic Segment Tree](https://github.com/Jinsun-Lee/algorithm-study/blob/master/Z26_ETC/_segmentTree/4_2042_%ED%83%91%EB%8B%A4%EC%9A%B4_0%EA%B8%B0%EB%B0%98_%EC%83%88%EA%B0%92%EB%8C%80%EC%9E%85_%EB%8B%A4%EC%9D%B4%EB%82%98%EB%AF%B9.cpp): 탑다운 / 0기반 / 위와 동일, <mark>다이나믹으로 트리의 크기를 필요한 만큼</mark> 잡는 게 달라
    - [x] 5. [Dynamic Segment Tree](https://github.com/Jinsun-Lee/algorithm-study/blob/master/Z26_ETC/_segmentTree/5_2042_%ED%83%91%EB%8B%A4%EC%9A%B4_0%EA%B8%B0%EB%B0%98_%EC%83%88%EA%B0%92%EB%8C%80%EC%9E%85_%EB%8B%A4%EC%9D%B4%EB%82%98%EB%AF%B9_%ED%8F%AC%EC%9D%B8%ED%84%B0%EB%A7%81%ED%81%AC%EB%93%9C%EB%A6%AC%EC%8A%A4%ED%8A%B8.cpp): 탑다운 / 0기반 / 위와 동일, 다이나믹을 <mark>포인터 기반의 링크드리스트</mark>로 구현함
    - [ ] 6. ⭐[Bottom-Up Segment Tree](https://github.com/Jinsun-Lee/algorithm-study/blob/master/Z26_ETC/_segmentTree/6_2042_%EB%B0%94%ED%85%80%EC%97%85_0%EA%B8%B0%EB%B0%98.cpp): 바텀업 / 0기반 / 위에 것들보다 훨 좋아... 근데 아래 것이 더 좋아
    - [ ] 7. ⭐[Bottom-Up Segment Tree](https://github.com/Jinsun-Lee/algorithm-study/blob/master/Z26_ETC/_segmentTree/7_2042_%EB%B0%94%ED%85%80%EC%97%85_0%EA%B8%B0%EB%B0%98_%EA%B0%84%EB%8B%A8.cpp): 바텀업 / 0기반 / 짱짱
    - [x] 8. [Top - Down Segment Tree with Lazy Propagation](https://github.com/Jinsun-Lee/algorithm-study/blob/master/Z26_ETC/_segmentTree/8_2042_%ED%83%91%EB%8B%A4%EC%9A%B4_0%EA%B8%B0%EB%B0%98_LAZY.cpp): 탑다운 / 0기반 / <mark>LAZY, 이 문제에서는 핵구려짐</mark>
- [x] [10999. 구간 합 구하기 2](https://www.acmicpc.net/problem/10999): lazy로 풀어
    - [ ] 9. ⭐⭐[Top - Down Segment Tree with Lazy Propagation](https://github.com/Jinsun-Lee/algorithm-study/blob/master/Z26_ETC/_segmentTree/9_10999_%ED%83%91%EB%8B%A4%EC%9A%B4_0%EA%B8%B0%EB%B0%98_LAZY.cpp): 탑다운 / 0기반 / LAZY
     
<br><br><br>

```cpp
// 3번. 탑다운, 0기반 

```

<br>

```cpp
// 6번 → 7번. 바텀업, 0기반

```

<br>

```cpp
// 8번 → 9번. 탑다운, LAZY

```
