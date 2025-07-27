#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int value[10];

int main()
{
	int N, end, begin;
	cin >> N;
    
    vector<pair<int, int>> schedule;
	for (int i = 0; i < N; i++){
		cin >> begin >> end;
		schedule.push_back(make_pair(end, begin));
	}
	
	sort(schedule.begin(), schedule.end());
	
	int time = schedule[0].first;
	int count = 1;
	for (int i = 1 ;i < N; i++) 
	{
		if (time <= schedule[i].second )
		{
			count++;
			time = schedule[i].first;
		}
	}

	cout << count;
    return 0;
}