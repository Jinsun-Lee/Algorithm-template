#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

struct Student {
	
	// 구조체, 코드에서 쓰임
	int cnt,year;
	char name;

	// 생성자 정의 >>>구조체변수(생성자변수)<<< 
	Student(int c,int y,char n): cnt(c),year(y),name(n){}
};

// 문제 풀이 수가 많은 것이 Top에 우선(내림차순) 9 8 7 6 
struct cmp{
	bool operator()(Student a,Student b){
		return a.cnt < b.cnt;
	}
};

int main(){
	// 위에서 만든 cmp 구조체를 넣어
	priority_queue<Student,vector<Student>,cmp> pq;

	int a,b; string c;
	int arr[3]={};
	for(int i = 0; i < 3; i++){
		cin >> a >> b >> c;
		arr[i]=b%100;
		pq.push(Student(a,b%100,c[0]));
	}

	// 입학 년도순
	sort(arr, arr+3);
	for(int i : arr) cout << i;
	cout << "\n";

	// 문제풀이별 순
	while(!pq.empty()) {
		cout << pq.top().name;
		pq.pop();
	}

	return 0;
}