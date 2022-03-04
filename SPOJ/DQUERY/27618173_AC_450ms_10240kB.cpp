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
#define F first
#define S second
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
string ys = "YES", no = "NO"; const int N =1<<20, M = 1 << 10;
const ll mod = 1e9 + 7;

int n, a[30005], q, qs[int(2e5) + 5], qe[int(2e5) + 5], qi[int(2e5) + 5], s, e, qa[int(2e5) + 5];
int cnt, frq[int(1e6) + 5];
void add(int val){
	cnt += !frq[val]++;
}
void remove(int val){
	cnt -= !--frq[val];
}
void update(int cur){
	while (e <= qe[cur])
		add(a[e++]);
	while (s>qs[cur])
		add(a[--s]);
	while (e>qe[cur] + 1)
		remove(a[--e]);
	while (s<qs[cur])
		remove(a[s++]);
}
void mo(){
	int sq = sqrt(n);
	sort(qi, qi + q, [sq](int a, int b){return make_pair(qs[a] / sq, qe[a]) < make_pair(qs[b] / sq, qe[b]); });
	s = e = 0;
	for (int i = 0; i < q; i++){
		int cur = qi[i];
		update(cur);
		qa[cur] = cnt;
	}
}

int main()
{
	//fast;
	//cin >> n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d",a+i);
	scanf("%d", &q);
	for (int i = 0; i < q;i++){
		qi[i] = i; cin >> qs[i] >> qe[i];
	     qs[i]--; qe[i]--;
	}
	mo();
	for (int i = 0; i < q; i++)cout << qa[i] << ed;
}