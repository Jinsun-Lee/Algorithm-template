#include <iostream>
using namespace std;

int n = 10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

// mid = (st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 이미 정렬이 되어있는 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.
void merge(int st, int en){
  int mid = (st+en)/2;
  
}

// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en){
  if(???????????) return; // 길이 1인 경우
  int mid = (st+en)/2;
  merge_sort(st, mid); // arr[st:mid]을 정렬한다.
  merge_sort(mid, en); // arr[mid:en]을 정렬한다.
  merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  merge_sort(0, n);
  // -53 3 12 15 16 22 23 25 46 357
  for(int i = 0; i < n; i++) cout << arr[i] << " ";  

  return 0;
}
