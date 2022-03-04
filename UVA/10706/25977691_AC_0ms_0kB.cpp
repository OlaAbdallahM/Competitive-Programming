#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
const ll OO = 1e18;
#define ed '\n'
#define F first
#define S second
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
string ys = "YES", no = "NO";const int N = 1 << 17, M = 1 << 10;
const ll mod = 1e9 + 7;
#define maxN 40000
ll sum[maxN];
string digit = "";

string toString(int n) {
	string res = "";
	while (n) {
		res += (n % 10) + 48;
		n /= 10;
	}
	reverse(all(res));
	return res;
}

int countDigit(int n) {
	int res = 0;
	while (n) { res++; n /= 10; }
	return res;
}

int main()
{
	fast
		ll tmp = 0LL;
	sum[0] = 0LL;
	for (int i = 1; i < maxN; i++) {
		tmp += countDigit(i);
		sum[i] = sum[i - 1] + tmp;
		digit += toString(i);
	}
	int cases, n;
	for (scanf("%d", &cases); cases--;) {
		scanf("%d", &n);
		int lo = 1, hi = maxN - 1, p = maxN - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (sum[mid] >= n)
				hi = mid - 1, p = min(p, mid);
			else lo = mid + 1;
		}
		cout << digit[n - sum[p - 1] - 1] << endl;
	}
	return 0;
}
