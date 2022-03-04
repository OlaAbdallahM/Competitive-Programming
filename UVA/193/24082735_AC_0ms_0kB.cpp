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
enum Color { white, black };
int n, m;
vector< vector<int> > adjList;
vector<int> bestBlacks, curBlacks;
vector<Color> curColor;
 bool canBeBlack(int cur)
{	// Neighbors must be white
	for(int nei : adjList[cur])
	{
		if (nei == cur || curColor[nei] == black)	// handle self loops
			return false;
	}
	return true;
}
void backtrack_3(int cur)
{
	if (bestBlacks.size() < curBlacks.size())
		bestBlacks = curBlacks;	// you have to check earlier..you may not reach cur = n
	if (cur == n)
		return ;
	int max_possible_blacks = n - cur;
	if(max_possible_blacks + curBlacks.size() <= bestBlacks.size())
		return;	// pruning: even if all next is black, we won't do well
	// Minimize depth: avoid big search tree
	for(int i = cur; i < n; ++i)
	{
		if (canBeBlack(i))	// switch to black
		{	// do...rec...undo
			curColor[i] = black;
			curBlacks.push_back(i);
			backtrack_3(i+1);
			curBlacks.pop_back();
			curColor[i] = white;
		}
	}
	// no need to call specific white, loop do so
}
int main(){
	fast();
	int tc; cin>>tc;
	while(tc--)
    {
        cin>>n>>m;
		adjList.clear();
		adjList.resize(n);
		curBlacks.clear();
		bestBlacks.clear();
		curColor = vector<Color>(n, white);
		for(int i=0;i<m;i++)
		{
			int f, t;
 
			cin>>f>>t;
			--f, --t;
			adjList[f].push_back(t);
			adjList[t].push_back(f);
		}
		backtrack_3(0);	// no need to handle disconnected components
		cout<<bestBlacks.size()<<"\n";
		string space = "";
		for(int x : bestBlacks)
			cout<<space<<x+1, space = " ";
		cout<<"\n";
	}
  return 0;
}