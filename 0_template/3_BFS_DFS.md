# Day3. DFS/BFS



### ⭐N과 M(3)
### ⭐N과 M(7)
### ⭐N과 M(11)

### ⭐N과 M(4)
### N과 M(8)
### N과 M(12)

### ⭐N과 M(2)
```cpp
int N, M;

int main() {
	cin >> N >> M;

	//for(int i = 0; i < N; i++) vec.push_back(i < M ? 0 : 1);

	vector<int> vec(N, 1);
	fill(vec.begin(), vec.begin() + M, 0);	

	do {
		for (int i = 0; i < N; i++) {
			if (vec[i] == 0) cout << i+1 << " ";
		}
		cout << "\n";
	} while (next_permutation(vec.begin(), vec.end()));

	return 0;
}

```

### N과 M(6)
### N과 M(10)

### ⭐N과 M(1)
### N과 M(5)
### N과 M(9)




