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
const int mod = 1e9 + 7, N = 1e5, M = 50000;


vector <ll> vc;
void solve(ll num)
{
	while (num % 2 == 0){
		vc.push_back(2);
		num /= 2;
	}

	for (ll i = 3; i <= sqrt(num + 0.9); i += 2){
		while (num % i == 0){
			vc.push_back(i);
			num /= i;
		}
	}

	if (num > 2) vc.push_back(num);

	// sort(vc.begin(), vc.end());
}

int main()
{

	ll tc, num, t = 1, pownum;

	while (cin >> num){

		if (num == 0) break;

		if (num < 0) {
			cout << num << " = -1 x ";
			num = abs(num);
		}
		else
			cout << num << " = ";

		vc.clear();
		solve(num);

		for (ll i = 0; i < vc.size() - 1; i++){
			cout << vc[i] << " x ";
		}
		cout << vc[vc.size() - 1] << endl;
	}

	return 0;
}