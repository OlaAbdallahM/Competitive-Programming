#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;


int dp[20];
int main(){
	
	int n, k; cin >> n >> k;

	dp[0] = 1, dp[1] = k - 1;

	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2])*(k - 1);

	cout << dp[n] << '\n';
}