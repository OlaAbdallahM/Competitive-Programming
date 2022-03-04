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
#define EPS 1e-12
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
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e8 + 7, N = 1e7;

int M[10][100];
int dp[10][100];
int nxt[10][99];
int r, c, aux, cur, x;
int main(){
	fast;
	while (cin>>r>>c){
		if (!r&&!c)break;
		for (int i = 0; i<r; i++)
		for (int j = 0; j<c; j++) cin>>M[i][j];

		for (int i = 0; i<r; i++) dp[i][c - 1] = M[i][c - 1];

		for (int i = c - 2; i >= 0; i--)
		for (int j = 0; j<r; j++){
			cur = INT_MAX;

			for (int k = -1; k <= 1; k++){
				aux = (j + k + r) % r;

				if (dp[aux][i + 1]<cur || (dp[aux][i + 1] == cur && aux<nxt[j][i])){
					cur = dp[aux][i + 1];
					nxt[j][i] = aux;
				}
			}

			dp[j][i] = M[j][i] + cur;
		}

		aux = INT_MAX;

		for (int i = 0; i<r; i++)
		if (dp[i][0]<aux){
			aux = dp[i][0];
			x = i;
		}

		cout<< x + 1;
		for (int i = 0; i<c - 1; i++){
			x = nxt[x][i];
			cout<<' '<<x+1;
			
		}
		cout<<ed<<aux<<ed;
	}

}