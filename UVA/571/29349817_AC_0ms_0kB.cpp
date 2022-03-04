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
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e9+7, N = 2e5, M = 5000;

string actions[] = { "fill B", "fill A", "empty B", "empty A", "pour B A", "pour A B", "Start" };
enum list		   { FILL_B, FILL_A, EMPTY_B, EMPTY_A, POUR_B_A, POUR_A_B, Start };

struct state 	   { int a, b, action; };

const int MAX = 1000 + 9;
bool reached[MAX][MAX];
state prev_state[MAX][MAX];
queue<state> qu;

int ca, cb, required;

void backtrace(state cur)
{
	if (cur.a == 0 && cur.b == 0)
		return;

	backtrace(prev_state[cur.a][cur.b]);
	cout << actions[cur.action] << "\n";
}

void add_state(int a, int b, int action, state parent)
{
	if (reached[a][b])
		return;

	state cur = { a, b, action };
	qu.push(cur);
	prev_state[a][b] = parent;
	reached[a][b] = true;
}

void BFS(int a, int b)
{
	qu = queue<state>();
	memset(reached, 0, sizeof(reached));

	add_state(0, 0, Start, state());

	while (!qu.empty())
	{
		state cur = qu.front();
		qu.pop();
		int a = cur.a, b = cur.b, aa, bb;

		if (b == required)	// Improvement: Catch it before adding to queue
		{
			backtrace(cur);
			cout << "success\n";
			return;
		}

		add_state(a, cb, FILL_B, cur);
		add_state(ca, b, FILL_A, cur);
		add_state(a, 0, EMPTY_B, cur);
		add_state(0, b, EMPTY_A, cur);

		aa = (a + b)>ca ? ca : a + b;
		bb = (a + b)>ca ? (a + b) - ca : 0;
		add_state(aa, bb, POUR_B_A, cur);

		aa = (a + b)>cb ? (a + b) - cb : 0;
		bb = (a + b)>cb ? cb : a + b;
		add_state(aa, bb, POUR_A_B, cur);
	}
}
// Your turn: Write Dijkstra version. Write DFS version

int main()
{
	fast;

	while (cin >> ca >> cb >> required)
		BFS(0, 0);

	return 0;
}