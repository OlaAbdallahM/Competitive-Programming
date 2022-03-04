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
const long double dgr = acos(-1) / 180;
const int mod = 1e9 + 7, N = 1e5 + 5;
map<int,int>mp;
int main()
{
	fast;
	int n, c,cnt=1; 
	while (cin >> n >> c){
		if (!n&&!c)break;
		cout << "Case "<<cnt++ << ":\n";
		list<int>q;
		for (int i = 1; i <=min(n,10000); i++)q.push_back(i);
		while (c--){
			char com; cin >> com;
			if (com == 'N'){
				cout << q.front() << ed;
				q.push_back(q.front());
				q.pop_front();
			}
			else {
				cin >> n;
				q.remove(n);
				q.push_front(n);
			}
		}
		mp.clear();
	}
}


