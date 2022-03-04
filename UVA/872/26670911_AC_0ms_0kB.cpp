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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;

bool imp;
bool adj[27][27];
bool avail[27];

void print(string s, int length)
{
	if (not length)
	{
		cout << s <<ed;
		imp = false;

		return;
	}

	for (int i = 0; i < 27; ++i)
	{
		if (avail[i])
		{
			bool small = true;

			for (int j = 0; j < 27; ++j)
				if (avail[j] && adj[j][i])
				{
					small = false;
					break;
				}

			if (small)
			{
				avail[i] = false;
				print(s + (s.empty() ? "" : " ") + (char)('A' + i), length - 1);
				avail[i] = true;
			}
		}
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		cin.ignore();
		int length = 0;
		string var;
		reset(adj, false);
		fill(avail, avail + 27, false);

		getline(cin, var);
		stringstream in;
		in << var;
		char a;
		while (in >> a)
		{

			++length;
			avail[a - 'A'] = true;
		}

		string s;
		getline(cin, s);

		in.clear();
		in.str(s);

		while (in >> a)
		{
			char b;
			in >> b >> b;
			adj[a - 'A'][b - 'A'] = true;
		}

		imp = true;

		print("", length);

		if (imp)
			cout << "NO\n";

		if (t)
			cout << "\n";
	}
}

	