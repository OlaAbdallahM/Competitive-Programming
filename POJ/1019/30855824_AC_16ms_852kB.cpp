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
const int mod = 1e9 + 7, N = 4e4 + 5, M = 5005;
#define  ll long long 


ll len[N], sum[N];

void init()
{
	len[0] = 0;
	sum[0] = 0;
	for (int i = 1; i < N; ++i)
	{
		len[i] = len[i - 1] + (int)log10((double)i) + 1;
		sum[i] = sum[i - 1] + len[i];
	}
}

int main()
{
	ll t, i, n, n1;
	init();
	cin >> t;
	while (t--)
	{
		cin >> n;
		i = 0;
		while (sum[i] < n)
			++i;
		n1 = n - sum[i - 1];
		i = 0;
		while (len[i] < n1)
			++i;
		cout << i / (ll)(pow(10.0, (double)(len[i] - n1))) % 10 << endl;
	}
}