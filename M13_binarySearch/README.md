# [이분탐색](https://github.com/Jinsun-Lee/Algorithm-template/discussions/13)

- [x] [1920. 수 찾기](https://www.acmicpc.net/problem/1920): 개념 확인 ([함수, STL](https://github.com/Jinsun-Lee/Algorithm-template/blob/master/M13_binarySearch/1_1920_%ED%95%A8%EC%88%98_STL.md))
- [ ] ⭐[10816. 숫자 카드 2](https://www.acmicpc.net/problem/10816): lower_bound ([함수, STL](https://github.com/Jinsun-Lee/Algorithm-template/blob/master/M13_binarySearch/2_10816_%ED%95%A8%EC%88%98_STL.md))
- [ ] ⭐[18870. 좌표 압축](https://www.acmicpc.net/problem/18870): 개념 숙지 ([STL](https://github.com/Jinsun-Lee/Algorithm-template/blob/master/M13_binarySearch/3_18870_STL.md))
- [ ] ⭐⭐[2805. 나무자르기](https://www.acmicpc.net/problem/2805): 개념 숙지 → 매개변수 탐색
    ```cpp
    #include <iostream> 
    #include <algorithm>
    using namespace std;
    
    int N, M, heights[1'000'001]; // 나무의수, 가져갈길이, 나무의높이들
    
    // 결정 문제: mid 높이에 절단기를 위치했을 때 m 길이 이상의 나무를 얻을 수 있는가?
    bool check(const int mid){
        long long sum = 0; // 오버플로우 조심
        for (int h : heights){
            if (h > mid) sum += (h - mid);
        }    
        return sum >= M;
    }
    
    int main(){
        ios::sync_with_stdio(0); cin.tie(0);
        
        cin >> N >> M;
        for (int i = 0; i < N; ++i) cin >> heights[i];
        
        int st = 0, en = 1e9; 
        int mid, ans = 0;
        
        while(st <= en){
            mid = (st + en) / 2;
            
            if (check(mid)){ // 성공조건
                ans = mid; // 어떤 조건 check(mid)를 만족하는 x의 최댓값 또는 최솟값 찾기
                st = mid + 1; // st랑 en이 바뀔 수는 있어
            }
            else en = mid -1;
        }
        
        cout << ans;    
        return 0;
    }
    ```

<br>

### 매개변수 탐색
- [x] [1654. 랜선자르기](https://www.acmicpc.net/problem/1654): [답](https://github.com/Jinsun-Lee/Algorithm-template/blob/master/M13_binarySearch/5_1654_%ED%95%A8%EC%88%98.cc) 
- [x] [1477. 휴게소 세우기](https://www.acmicpc.net/problem/1477): [답](https://github.com/Jinsun-Lee/Algorithm-template/discussions/13#discussioncomment-12961024)
- [x] [16401. 과자 나눠주기](https://www.acmicpc.net/problem/16401): [답](https://github.com/Jinsun-Lee/Algorithm-template/discussions/13#discussioncomment-13635307)
