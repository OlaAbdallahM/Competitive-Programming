#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e16;
#define ed '\n'
#define F first
//#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e9 + 7, N = 1e5 + 5, M = 50000;

//     https://www.youtube.com/watch?v=ifTqIif9WJg
const int G = 34943;

int main()
{
	for (;;) {
		unsigned int a = 0;
		unsigned char c;
		int cnt = 0;

		while (scanf("%c", &c) == 1 && c != '#' && c != '\n') {
			cnt++;
			a = ((a << 8) + c) % G;
		}

		// determine the end condition
		if (cnt == 0 && c == '#')
			break;

		// shift to high byte, calculate CRC
		a = (a << 16) % G;
		if (a)
			a = G - a;

		unsigned char *p = (unsigned char *)&a;
		printf("%02X %02X\n", *(p + 1), *p);
	}

	return 0;
}
