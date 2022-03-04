#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using ll = long long;
const ll OO = 1e18;
#define ed '\n'
#define F first
#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define all(c) c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define fr(i,l,n)for(int i=l;i<n;i++)
#define stpr(n)fixed<<setprecision(n)
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 1 << 20;
int main()
{
	unsigned long long c;
	while (cin >> c)
	{
		if (c == 0)break;
		unsigned long long N = (c * 10) / 9;
		vector<unsigned long long> a;
		a.push_back(N);
		N--;
			while (N - (N / 10) == c)
			{
				a.push_back(N);
				N--;
			}
		sort(a.begin(), a.end());
		cout << a[0];
		for (int i = 1; i<a.size(); i++)cout << " " << a[i];
		cout << endl;
	}
	return 0;

}