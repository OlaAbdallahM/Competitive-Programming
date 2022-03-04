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
string ys = "YES", no = "NO"; const int N =1<<20, M = 1 << 10;
map<pii, int>mp;

ll Catalan[30];

void __getCatalan(){
	Catalan[0] = Catalan[1] = 1, Catalan[2] = 2;
	for (ll n = 3; n <= 26LL;n++) Catalan[n] = Catalan[n - 1] * (2 * (n * 2 - 1)) / (n + 1);
}
int main(){
	__getCatalan();
	ll n;
	while (cin>>n){
		int Cnt = 0;
		for (int i = 1; i <= 26;i++){
			if (Catalan[i] > n) break;
			Cnt++;
		}
		cout<<Cnt<<ed;
	}
}