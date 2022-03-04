#include<bits/stdc++.h>


using namespace std;
using ll = long long;
const ll OO = 1e18;
#define ed '\n'

#define sz(a)a.size()
#define vi vector<int>

#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0


#define reset(mem,val)memset(mem,val,sizeof mem)

string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;

ll gcd(ll a, ll b)
{
	return (!b ? a : gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)*b);
}

int main(){

	int t; cin >> t;
	while (t--){
		int a, b, c; cin >> a >> b >> c; 
		cout << (a&&b&&c && (a + b + c) == 180 ? ys : no) << ed;
	}
}
