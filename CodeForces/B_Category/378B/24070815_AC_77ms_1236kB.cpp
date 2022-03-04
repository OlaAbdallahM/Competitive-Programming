#define _CRT_SECURE_NO_WARNINGS
//   Allah_Almost3aan
#include<bits/stdc++.h>
//#include <unordered_map>
using namespace std;
#define  ll  long long
//const ll OO = 1e18;
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
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}const int N=1e5+5;
int main(){
	fast();
	int n; cin>>n;
	vector<int>a(n),b(n);
	string r1,r2;
	for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        r1.push_back('0');
        r2.push_back('0');
    }
    for(int i=0;i<n/2;i++)r1[i]=r2[i]='1';
    for(int i=0,j=0,cnt=0;cnt<n;cnt++)
      if(j==n||a[i]<b[j])r1[i++]='1';
      else r2[j++]='1';
      cout<<r1<<ed<<r2<<ed;
}
