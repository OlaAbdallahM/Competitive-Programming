#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll =  long long;
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
string ys = "YES", no = "NO"; const int N = 50005, M = 1 << 10;
const ll mod = 1e9 + 7;
 
 
 
int phi[N];
 
void init(){
	reset(phi,0);
	phi[1] = 1;
	for (int i = 2; i < N; ++i){
		if (!phi[i]){
			for (int j = i; j < N; j += i){
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}
 
int main()
{
	int n;
	init();
	while (cin >> n&&n){
		int ans = 0;
		for (int i = 2; i <= n; ++i){
			ans += phi[i];
		}
		cout << ans * 2 + 1 << endl;
	}
	return 0;
}