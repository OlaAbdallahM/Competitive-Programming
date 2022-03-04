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
string ys = "YES", no = "NO"; const int N = 1 << 30, M = 1 << 10;
const ll mod = 1e9 + 7;

int dp[M][M]; vi v;
int n, c, l;

int calc(int p){
	if (!p)return 0;
	else if (p <= 10)return -c;
	else return (p - 10)*(p - 10);
}

int solve(int i, int lec){
	int &rt = dp[i][lec];
	if (rt <= N)return rt;
	if (!lec)
	if (i == n)return rt = 0;
	else return rt = N;
	
	int sum = 0;
	for (int j = i; j < n; j++){
		sum += v[j];
		if (sum>l)break;
		int tmp = solve(j + 1, lec - 1);
		if (tmp != N)rt = min(rt, tmp + calc(l - sum));
	}
	if (rt >= N)return rt = N;
	return rt;
}
int main(){
	int t = 1;
	while (cin >> n&&n)
	{
		if (t > 1)cout << ed;

		cin >> l >> c;
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		int lec = 0, sum = 0;
		for (int i = 0; i < n; i++){
			sum += v[i];
			if (sum>l){
				sum = v[i];
				lec++;
			}
		}
		lec++;
		reset(dp, 0x7f);
		cout << "Case " << t++ << ":\nMinimum number of lectures: " << lec << "\nTotal dissatisfaction index: " << solve(0, lec) << ed;
	}
}