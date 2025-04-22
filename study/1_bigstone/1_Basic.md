# 빠르게 넘길 수 있는 부분

1. 숫자 N개가 주어진다고 하고, N개 받고 최대값 출력  
   `int max=-99999;` 음수랑 비교할 때 주의, 걍 엄청 크게 둘 것
   
2. 최소값 출력하기

3. 동적할당 배열로 전부 받아서 sort하기
   ```
   int* arr = new int[tCase];
   sort(arr, arr + tCase);
   ```
   `sort(arr.begin(), arr.end());` 이건 벡터인 것 주의  
    `cout << arr;` 얘는 배열의 인덱스 0번의 주소  
    `cout << arr+1;` 얘는 1번의 주소  
    `cout << *arr;` 얘는 배열의 인덱스 0번의 값   
    `cout << *arr+1;` 얘는 0번의 값에 1을 더한 값, 1번의 값이 아님  
    `cout << *(arr+1);` 얘가 인덱스 1번의 값  
    `cout << &arr;` 얘는 동작 안 함  

    <br>

    3-1. 150cm 미만의 키 값을 오름차순으로 출력하기 [입력](https://github.com/Jinsun-Lee/coding_test/blob/master/template/Day1/input3_1.txt)

    ```
    for (int i = 0; i < tCase; i++) {
    	if (arr[i] >= 150) break;
	    cout << arr[i] << " ";      
    }
    ```
    ```
    for (int i = 0; i < tCase; i++) {
    	if (arr[i] < 150) {
            cout << arr[i] << " ";     
        }
    }
    ```

<br>

4. 동적할당으로 선언한 배열의 경우, 크기가 바뀌면 불편함  
   벡터를 쓰면 간단(근데 얘는 메모리 주소가 계속 바뀌기 때문에 정적보다 더 느림)
     
   1차원 벡터
   ```
   vector<int> v(5, 0);               //output : 0 0 0 0 0
   v.assign(5, 1);                    //output : 1 1 1 1 1

   vector<int> v = vector<int>(5);    //output : 0 0 0 0 0
   vector<int> v = vector<int>(5, 1); //output : 1 1 1 1 1
   ```
   ```
   vector<int> v = { 1, 2, 3, 4, 5 }; 

   for (int i = 0; i < v.size(); i++) {
    cout << v.at(i) << " ";           //output : 1 2 3 4 5
   } 
   ```
   ```
   void callByValue(vector<int> list) {    // 원본에 영향이 없음
     list.clear();
   }

   void callByAddress(vector<int>& list) { // 원본 데이터가 바뀜
     list.clear();
   }

   void change(int array[]) {   // 기본적으로 주소라, 원본이 바뀜
     array[0] = 10;
   }

   callByValue(list);   //output : {1, 2, 3}
   callByAddress(list); //output : {}
   ```
   ```
   int array[] = { 1, 2, 3 };

   change(array);       //output : {10, 2, 3}

   for (int i = 0; i < size(array); i++) {
       cout << array[i] << " ";
   }
   ```

5. 2차원 벡터
   ```
   vector<vector<int>> vec;
   vec = vector<vector<int>> (5); // 5개의 row만큼 정의
   vec = vector<vector<int>> (5, vector<int>(3, 1)); // 5개의 row, 3개의 col을 1로 채워서 정의
   ```
   
6. 벡터 sort
   ```
   #include <iostream>
   #include <vector>
   #include <algorithm>

   using namespace std;

   void compare(vector<int>& node) {
       sort(node.begin(), node.end());
   }

   int main() {
       vector<vector<int>> nodeList = vector<vector<int>>(N + 1);

       // 세로로 sort
       sort(nodeList.begin(), nodeList.end());

       // 가로로 sort
       // 방법 1
       for(vector<int> &node : nodeList) {
              sort(node.begin(), node.end());
       }

       // 방법 2
       for(int i = 0; i < nodeList.size(); i++) {
              sort(nodeList[i].begin(), nodeList[i].end());
       }

       // 방법 3
       for_each(nodeList.begin(), nodeList.end(), [](vector<int>& node) { sort(node.begin(), node.end()); } );

       // 방법 4
       for_each(nodeList.begin(), nodeList.end(), compare);
   ```
   
---

<br>

### Day2. 문자열  

1. 각 알파벳이 몇 번씩 출력되는지 [입력](https://github.com/Jinsun-Lee/coding_test/blob/master/template/Day2/input.txt)  
   <details>
   <summary>답</summary>

   ```
   int main() {
        string input = "";
        int* cnt = new int[26] {0}; //⭐
        freopen_s(new FILE*, "input.txt", "r", stdin);
        cin >> input;

        int index;
        for (int i = 0; i < input.length(); i++) {
            index = input[i] - 'a'; //⭐int to char (a 대신 48도 됨)
            cnt[index]++;
        }

        //sort(cnt, cnt + input.length()); // ⭐
        for (int j = 0; j < 26; j++) { 
            if (cnt[j]==0) continue; 
            cout << (char)('a'+ j) << ": " << cnt[j] << "\n"; //⭐
        }
        return 0;
    }
   ```
   </details>

<br>

2. 문자열 추출: moon이 나오는 횟수
    <details>
    <summary>입력</summary>
    
    ```
    string str = "moonshining through the night, reflecting on the still waters of the lake, illuminating dreams untold and stories unwritten. stars twinkle alongside the celestial beauty, painting a tapestry of light across the sky. with every breath, the world whispers secrets of its ancient past, and the moon watches silently, a sentinel of time. through valleys deep and mountains high, the echoes of its silver glow bring solace to the weary and inspiration to the dreamers. moonlit paths guide travelers toward destinations unseen, and the soft glow dances on the waves, creating ripples of wonder and tranquility.beyond the horizon, the moon hangs steady, a constant in an ever-changing world, a reminder that even in the darkest nights, light persists, and beauty prevails. the moon, a muse to poets and artists, a guide to wanderers, a symbol of hope and renewal.as the moon's light fades with the dawn, it leaves behind a promise to return, to grace the night once more with its timeless glow.";
    ```
    </details>

    <details>
    <summary>답: 6</summary>
    
    ```
    int main() {
        string str = "moonshining through the night, reflecting on the still waters of the lake, illuminating dreams untold and stories unwritten. stars twinkle alongside the celestial beauty, painting a tapestry of light across the sky. with every breath, the world whispers secrets of its ancient past, and the moon watches silently, a sentinel of time. through valleys deep and mountains high, the echoes of its silver glow bring solace to the weary and inspiration to the dreamers. moonlit paths guide travelers toward destinations unseen, and the soft glow dances on the waves, creating ripples of wonder and tranquility.beyond the horizon, the moon hangs steady, a constant in an ever-changing world, a reminder that even in the darkest nights, light persists, and beauty prevails. the moon, a muse to poets and artists, a guide to wanderers, a symbol of hope and renewal.as the moon's light fades with the dawn, it leaves behind a promise to return, to grace the night once more with its timeless glow.";
        
        string targetStr = "moon";

        int cnt = 0;
        int index = 0; //⭐

        while (1) {
            index = str.find(targetStr, index); //⭐
            if (index == -1) break;

            cnt++;
            index++; //⭐
        }
        cout << cnt;
        return 0;
    }
    ```
    ```
    string result = "";
    int index = -1; //⭐

    while (1) {
        index = str.find(targetStr, index+1);
        if (index == -1) break;

        result = str.substr(index, 4); //⭐
        cout << result << "\n";
        cnt++;
    }
    cout << cnt;
    ```
    </details>

<br>

---

<br>

### Day3. DFS     

<details>
<summary>1번. 000 ~ 999 배열</summary>

```
int dep = 3;

void dfs(int depth, string result) {
    if (depth >= dep) {
        cout << result << "\n";
        return;
    }

    for (int i = 0; i < 10; i++) {
        result = result + to_string(i);
        dfs(depth + 1, result);
        result.pop_back();
    }
}

int main() {
    dfs(0, "");
    return 0;
}
```
```
int dep = 3;
string num = "0123456789";

void dfs(int depth, string result) {
    if (depth >= dep) {
        cout << result << "\n";
        return;
    }

    for (int i = 0; i < num.length(); i++) { //
        result = result + num[i]; //
        dfs(depth + 1, result);
        result.pop_back();
    }
}

int main() {
    dfs(0, "");
    return 0;
}
```
</details>

<details>
<summary>2번. aaa ~ zzz 배열</summary>

```
int dep = 3;

void dfs(int depth, string result) {
    if (depth >= dep) {
        cout << result << "\n";
        return;
    }

    for (int i = 0; i < 26; i++) { // 여기랑 아래만 달라짐
        result = result + char(i+65); // 65면 대문자, 97이면 소문자
        dfs(depth + 1, result);
        result.pop_back();
    }
}

int main() {
    dfs(0, "");
    return 0;
}
```
```
int dep = 3;
string alpha = "abcdefghijklmnopqrstuvwxyz";

void dfs(int depth, string result) {
    if (depth >= dep) {
        cout << result << "\n";
        return;
    }

    for (int i = 0; i < alpha.length(); i++) { //
        result = result + alpha[i]; //
        dfs(depth + 1, result);
        result.pop_back();
    }
}

int main() {
    dfs(0, "");
    return 0;
}
```
</details>

<details>
<summary>3번. 000 ~ 999 벡터</summary>

</details>

<details>
<summary>4번. aaa ~ zzz 벡터</summary>

</details>

</br>

<details>
<summary>5번. 3개의 숫자 합이 15가 되는 경우 출력</summary>

```
int dep = 3;

void dfs(int depth, int sum, string result) {
    if (depth >= dep) {
        if (sum == 15) cout << result << "\n";
        return;
    }

    for (int i = 0; i < 10; i++) { 
        result = result + to_string(i);
        sum = sum + i;
        dfs(depth + 1, sum, result);
        result.pop_back();
        sum = sum - i;
    }
}

int main() {
    dfs(0, 0, "");
    return 0;
}
```
</details>

<details>
<summary>6번. (벡터) 5번 문제 구현</summary>

```
int dep = 3;

void dfs(int depth, vector<int> &vec) {
    
    if (depth >= dep) {
        
        int sum = 0;
        for (int i : vec) {
            sum = sum + i;
        }

        if (sum == 15) {
            for (int i : vec) {
                cout << i;
            }
            cout << "\n";
        }

        return;
    }

    for (int i = 0; i < 10; i++) { 
        vec.push_back(i);
        dfs(depth + 1, vec);
        vec.pop_back();
    }
}

int main() {
    vector<int> vec;
    dfs(0, vec);
    return 0;
}
```
</details>

<details>
<summary>7번. (배열) 5번 문제 + 숫자 한번만 사용(555 같은 거 안 나오게)</summary>

```
int dep = 3;
int visited[10] = {0};

void dfs(int depth, int sum, string result) {
    if (depth >=dep) {
        if (sum == 15) cout << result << "\n";
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (visited[i]) continue;

        sum += i;
        result += to_string(i);
        visited[i] = 1;
        dfs(depth+1, sum, result);
        sum -= i;
        result.pop_back();
        visited[i] = 0;
    }
}

int main() {
    dfs(0, 0, "");
    return 0;
}
```
</details>

<details>
<summary>8번. (배열X) 5번 문제 + 중복 없게(069 나오면 096 609 690 906 960 안 나오게)</summary>

```
int dep = 3;

void dfs(int depth, int sum, string result, int start) {
    if (depth >=dep) {
        if (sum == 15) cout << result << "\n";
        return;
    }

    for (int i = start; i < 10; i++) {
        sum += i;
        result += to_string(i);
        dfs(depth+1, sum, result, i);
        sum -= i;
        result.pop_back();
    }
}

int main() {
    dfs(0, 0, "", 0);
    return 0;
}
```
</details>

<details>
<summary>9번. 8번에서 555 안 나오게</summary>

```
dfs(depth+1, sum, result, i+1);
```
i는 중복조합 = 555  
i+1로 쓰면 조합(555 안 나옴)
</details>

<details>
<summary>10번. 합 최대/최소 구하기(9+9+9=27, 0+0+0=0)</summary>

```
int dep = 3;
int minNum = 987654321;
int maxNum = -987654321;
string minStr = "";
string maxStr = "";

void dfs(int depth, int sum, string result) {
    if (depth >=dep) {
        if (sum < minNum) {
            minNum = sum;
            minStr = result;
        }
        if (sum > maxNum) {
            maxNum = sum;
            maxStr = result;
        }
        return;
    }

    for (int i = 0; i < 10; i++) {
        sum += i;
        result += to_string(i);
        dfs(depth+1, sum, result);
        sum -= i;
        result.pop_back();
    }
}

int main() {
    dfs(0, 0, "");
    cout << minNum << "\n";
    cout << maxNum;
    return 0;
}
```
</details>
