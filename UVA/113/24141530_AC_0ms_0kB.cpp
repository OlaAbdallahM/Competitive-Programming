#define _CRT_SECURE_NO_WARNINGS
//   Allah_Almost3aan 
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using  ll = long long;
const ll OO = 1e18;
#define MOD 1e9+7
#define fnt 0x3f3f3f3f
#define ed '\n'
#define ff first
#define ss second
#define sz(a) a.size()
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define RT(v)return cout<<v<<ed,0
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define show(x) cout << (#x)<<" = "<<x<<ed
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
const int N = 5e5;
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int main(){
	//fast();
	 double n, p;
	 while (scanf("%lf%lf", &n, &p) != EOF)
		 printf("%.0lf\n", pow(p, 1 / n));
}