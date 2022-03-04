#define _CRT_SECURE_NO_WARNINGS
//   Allah_Almost3aan
#include<bits/stdc++.h>
//#include <unordered_map>
using namespace std;
 #define ll  long long
//#define MOD 1e9+7
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
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
const ll OO = 1e18,MOD=2000000011;
void fast() {
ios::sync_with_stdio(false);
cin.tie(0); cout.tie(0);}
//**************************************
ll fast_power(ll base, ll power,ll mod)
{
	ll ans = 1;
	while (power > 0){
		if (power & 1) ans = (ans*base) % mod;
		base = (base*base) % mod;
		power >>= 1;
	}
	return ans;
}
int main(){
	fast();
	int t; cin>>t;
	for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        int n; cin>>n;
        if(n==0)
            cout<<0<<ed;
        else if (n==1)
            cout<<1<<ed;
        else
            cout<<fast_power(n,n-2,MOD)<<ed;
    }
return 0;
}
