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

int used[M];

struct val{
	int l, r;
}v[M];

bool cmp(val x, val y){
	return x.l == y.l ? x.r < y.r : x.l < y.l;
}

int main(){
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 0; i < n; i++)cin >> v[i].l >> v[i].r;
		sort(v, v + n, cmp);
		memset(used, 0, sizeof used);
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (used[i])continue;
			int mx = v[i].r;
			for (int j = i + 1; j < n; j++){
				if (mx <= v[j].r&&!used[j]){
					mx = v[j].r;
					used[j]++;
				}
			}
			ans++;
		}
		cout << ans << '\n';
	}
}