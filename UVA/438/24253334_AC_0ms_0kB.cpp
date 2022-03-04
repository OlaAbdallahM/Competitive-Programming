#define _CRT_SECURE_NO_WARNINGS
//  Allah_Almost3aan 
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using  ll = long long;
const ll OO = 1e18;
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
#define show(x) cout << (#x)<<" = "<<x<<ed
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
const int N = 2e5 + 5;
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);}
int main(){
	fast();
	double x1, y1, x2, y2, x3, y3,a,b,c,cz,angl,R, PI = 3.141592653589793;
	while (cin >> x1 >> y1)
	{
		cin >> x2 >> y2 >> x3 >> y3;
		a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
		c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
		cz = (a*a + c*c - b*b) / (2 * a*c);
		angl = acos(cz);
		R = b / sin(angl);
		cout << stpr(2) << R*PI << ed;
	}
}