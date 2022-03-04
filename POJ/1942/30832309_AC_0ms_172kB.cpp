#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah Almost3aan
Make it happens :) */
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long  ncr(int n, int r)
{
	if (r > n - r)r = n - r;
	long long  ans = 1, j = 2;
	for (int i = n - r + 1; i <= n; i++)
	{
		ans *= i;
		while (!(ans%j) && j <= r)
		{
			ans /= j; j++;
		}
	}
	return ans;
}
long long gcd(long long a, long long  b){
	return(!b ? a : gcd(b, a%b));
}

int main(){
	long long n, m; 
	while (cin >> n >> m){
		n += m;
		if (!n&&!m)break;
		m = min(n - m, m);
		long long s1 = 1, s2 = 1, t;
	
		for (long long i = n, k = m; k>0; k--, i--){
			s1 = s1*i;
			s2 = s2*k;
			t = gcd(s1, s2);
			s1 = s1 / t;
			s2 = s2 / t;
		}
		cout << s1 / s2 << '\n';;
	}
}