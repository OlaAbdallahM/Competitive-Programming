#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using ll = long long;
#define ed '\n'
#define F first
#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
const ll OO = 0x3f3f3f3f3f3f3f3fLL;
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 2e5 + 5, M = (1 << 10) + 10;
const ll mod = 1e9 + 7;


int main()
{
	fast;
	int n; cin >> n;
	vi a(n), b(n), c(n);
	for (auto &i : a)cin >> i;
	for (auto &i : b)cin >> i;
	for (auto &i : c)cin >> i;
	sort(all(a));sort(all(b));sort(all(c));

	int i = 0, j = 0, k = 0, ans = 0;

	while (i < n && j < n && k < n){
		if (a[i]<b[j]){
			if (b[j]< c[k]){
				ans++;i++;j++;k++;
			}
			else k++;
		}
		else j++;
	}
	cout << ans<<ed;
}