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

ll numofTriangle[N], save[N];

void NumOfTriangleCalculate()
{
	numofTriangle[3] = 0;
	save[3] = 0;

	ll extra = 0;
	for (ll i = 4; i <= 1000000; i++){

		if (i % 2 == 0) extra++;

		save[i] = save[i - 1] + extra;
		numofTriangle[i] = numofTriangle[i - 1] + save[i];
	}

}


int main()
{
	NumOfTriangleCalculate();

	ll tc, num, t = 1, pownum;
	while (cin >> num && num >= 3)
		cout << numofTriangle[num] << endl;

	return 0;
}