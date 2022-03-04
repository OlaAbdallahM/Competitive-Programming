#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah Almost3aan
Make it happens :) */
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int cir[205];
int key[205];

int main(){

	int n, time;;
	while (cin >> n, n){
		for (int i = 0; i < n; i++)
			cin >> key[i],key[i]--;
		while (cin >> time, time)
		{
	
			string s;
			char ans[205];
			getchar();
			getline(cin, s);
			int m = s.length();
			s += string(n - m, ' ');
			for (int i = 0; i < n; i++)
			{
				int now = key[key[i]];
				cir[i] = 1;
				while (now != key[i])
				{
					cir[i]++;
					now = key[now];
				}
			}
			for (int i = 0; i < n; i++)
			{
				int cur_time = time%cir[i];
				int pos = i;
				while (cur_time--)
				{
					pos = key[pos];
				}
				ans[pos] = s[i];
			}
			

			for (int i = 0; i < n; i++)
				cout << ans[i];
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}