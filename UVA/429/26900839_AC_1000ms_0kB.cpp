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


int main() {

	fast; 
	int t;  cin >> t;
	while (t--){
		vector<string> words;

		string word;
		while (cin >> word, word != "*")
			words.push_back(word);

		cin.ignore();

		string line;
		while (getline(cin, line) && line != "")
		{
			stringstream ss(line);
			string s, t;
			ss >> s >> t;
			// BFS
			queue<string> q;
			map<string, int> trans;

			trans[s] = 0;
			q.push(s);
			while (sz(q) && trans.count(t) == 0)
			{
				string u = q.front();
				q.pop();
				// Loop over every word in the dictionary.
				for (auto i:words)
				{
					const string &v = i;
					if (!trans.count(v) && sz(u )== sz(v))
					{
						int diff = 0;
						for (int j = 0; j < sz(u); ++j)
						if (u[j] != v[j])
							++diff;
						if (diff == 1)
						{
							trans[v] = trans[u] + 1;
							q.push(v);
						}
					}
				}
			}
			cout << s << " " << t << " " << trans[t] << ed;
		}
		if (t)
			cout << ed;
	}
}