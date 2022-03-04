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

long long fib(int n){
	if (n < 3)return 1;
	return fib(n - 1) + fib(n - 2);
}

int main(){
	
	int n;
	while (cin >> n, n){
		if (n <= 3)cout << n << '\n';
		else cout << fib(n+1) << '\n';
	}
}