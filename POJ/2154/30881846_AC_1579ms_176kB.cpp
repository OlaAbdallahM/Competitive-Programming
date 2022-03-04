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

int n, p;

int euler(int n){   
	int res = n, a = n;
	for (int i = 2; i*i <= a; i++){
		if (a%i == 0){
			res = res / i*(i - 1);
			while (a%i == 0) a /= i;
		}
	}
	if (a>1) res = res / a*(a - 1);
	return res%p;
}

ll fast_power(ll base, ll power)
{
	ll ans = 1;
	while (power > 0){
		if (power & 1) ans = (ans*base) % p;
		base = (base*base) %p;
		power >>= 1;
	}
	return ans;
}


int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> p;
		int ans = 0;
		for (int i = 1; i*i <= n; i++)
		{
			if (n%i == 0)
			{
				ans = (ans + (euler(n / i)*fast_power(n%p, i - 1))) % p;
				if (i*i != n)
					ans = (ans + (euler(i)*fast_power(n%p, (n / i) - 1))) % p;

			}
		}
		cout << ans << '\n';
	}
	return 0;
}