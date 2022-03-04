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
const int N = 2e5+5;
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int main(){
//fast();
	int t;
	cin >> t;

	for (int i = 0; i < t; i++){
		ll low, high, v;
		cin >> low >> high;

		int mx = 0;
		for (ll j = low; j <= high; j++){
			int con = 0;
			double limit = sqrt(j);
			for (int k = 1; k <= limit; k++){
				if (j % k == 0){
					con++;
					if (k < limit)
						con++;
				}
			}
			if (mx < con)
				mx = con, v = j;
		}

		cout << "Between " << low << " and " << high << ", " << v << " has a maximum of " << mx << " divisors." << endl;
	}
}