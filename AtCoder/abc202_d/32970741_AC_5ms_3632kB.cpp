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
string ys = "YES", no = "NO"; const int N = 1e5 + 5, M = (1 << 10) + 10;
const ll mod = 1e9 + 7;



vector<vector<ll>>C(66, vector<ll>(66));
void nCr()
{
	C[0][0] = 1;
	for (int i = 1; i <= 60; i++){
		C[i][0] = 1;
		for (int j = 1; j <= 60; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	C[i][i] = 1;
	}
}


int main(){    // not my own idea
	fast
	ll a,b,k;cin >> a >> b >> k;
	nCr();
	while (a > 0 && b > 0){
		if (k <= C[a - 1+b][b]){
			cout << 'a';
			a--;
		}
		else {
			k-= C[a - 1+b][b];
			cout << 'b';
			b--;
		}
	}
	cout << string(a, 'a');
	cout << string(b, 'b');
	cout << ed;
	return 0;
}