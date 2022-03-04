#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah Almost3aan
Make it happens :) */
//#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;
//using ll = long long;
//using ld = long double;
//const ll OO = 1e18, oo = 1e12 + 21;
#define ed '\n'
#define EPS 1e-10
#define PI acos(-1.0)
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO";
//const long double dgr = acos(-1) / 180, rad = 180 / acos(-1);
//const ll mod = 1e9 + 7, N = 1e5 + 5, M = 5005;

int c[30][30], len, ans;
char str[15];

int main(){
	fast;

	for (int i = 0; i <= 26; i++)
	for (int j = 0; j <= i; j++)
	if (!j || i == j)
		c[i][j] = 1;
	else
		c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	c[0][0] = 0;
	string s; cin >> s;
	len = sz(s);
	for (int i = 1; i < len; i++)
	if (s[i] <= s[i-1])RT(0);
	
	int ans = 0;
	
	// calc number of strings with length less than len
	for (int i = 1; i < len; i++)ans += c[26][i];

	// calc number of strings with length equal to len
	for (int i = 0; i < len; i++){
		int ch = s[i] - 'a', ch2;

		if (!i)ch2 = 0;
		else ch2 = s[i - 1] - 'a' + 1;

		if (i == len - 1)ans += ch - ch2;
		else {
			while (ch2 < ch){
				ans += c[26 - ch2 - 1][len - i - 1];
				ch2++;
			}
		}
	}
	cout << ans + 1 << ed;
}