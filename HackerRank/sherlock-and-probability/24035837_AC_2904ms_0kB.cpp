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
const ll OO = 1e18;
const int N=1e5+5;
void fast() {
ios::sync_with_stdio(false);
cin.tie(0); cout.tie(0);}
//*************************************
int sum[N];
int main(){
	fast();
	int t; cin>>t;
	while(t--)
    {
      int n,k; cin>>n>>k;
      string s; cin>>s;
      sum[0]=s[0]-'0';
     for(int i=1;i<n;i++)
         sum[i]=sum[i-1]+(s[i]-'0');
     ll a=0,b=(ll)n*n;
     for(int i=0;i<n;i++)
         if(s[i]=='1')
         {
             int r=min(i+k,n-1);
             a+=2*(sum[r]-sum[i-1])-1;
         }
     ll g=__gcd(a,b);
     a/=g;
     b/=g;
     cout<<a<<'/'<<b<<ed;
	}

return 0;
}
