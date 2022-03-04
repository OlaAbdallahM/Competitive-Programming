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
const int mod = 1e9 + 7, N = 1e6 + 5, M = 5005;



struct DNA{
	int inv;
	string s;
	DNA(){}
}v[100];

bool cmp(DNA x, DNA y){
	return x.inv<y.inv;
}

int main(){
	
	int n, m; cin >> n >> m;

	for (int i = 0; i<m; ++i){
		cin >> v[i].s;

		v[i].inv = 0;
		for (int j = 0; j<n; ++j)
		for (int k = j + 1; k<n; ++k)
		if (v[i].s[j]>v[i].s[k])
			++v[i].inv;
	}

	stable_sort(v, v + m, cmp);

	for (int i = 0; i < m; ++i)
		cout << v[i].s << '\n';

	return 0;
}