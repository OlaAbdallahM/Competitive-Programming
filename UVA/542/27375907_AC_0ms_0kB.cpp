#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
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
string ys = "YES", no = "NO"; const int N = 4 * (1 << 17), M = 1 << 10;
const ll mod = 1e9 + 7;



int main()
{
	fast;
	vector<string> v(16);

	for (auto &i : v) cin >> i;

	vector<vector<double> > beat(16, vector<double>(16));

	for (int i = 0; i < 16; ++i)
	for (int j = 0; j < 16; ++j)
	{
		cin >> beat[i][j];
		beat[i][j] /= 100;
	}

	vector<double> p1(16, 1);
	vector<double> p2(16);

	for (int i = 0, g = 1; i < 4; ++i, g *= 2)
	{
		for (int j = 0; j < 16; ++j)
		{
			int cur = j / g;

			int start;
			if (cur % 2 == 0)
				start = cur * g + g;
			else
				start = cur * g - g;

			p2[j] = 0;

			for (int x = 0; x < g; ++x)
				p2[j] += p1[start + x] * beat[j][start + x];

			p2[j] *= p1[j];
		}

		p1 = p2;
	}

	for (int i = 0; i < 16; ++i)
	{
		p1[i] *= 100;
		cout << std::left<<setw(10) << v[i] << " p=" << stpr(2) << p1[i] << "%\n";
	}
}