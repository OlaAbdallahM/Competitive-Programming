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
#define ff first
#define ss second
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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;
const auto EPS = 1e-9;

//                                   NOT MY CODE
typedef struct{
	int q;
	int p;
}parts;

map<string, int> name;
vector<parts> components[1010];
int intType = 0;

bool valid(int q, int budget){
	int sum = 0;
	int maxType = name.size();
	for (int i = 0; i<maxType; i++){
		int minp = 1000005;
		for (unsigned int j = 0; j<components[i].size(); j++){
			if (components[i][j].q >= q){
				minp = min(minp, components[i][j].p);
			}
		}
		sum += minp;
	}
	if (sum>budget){
		return false;
	}
	return true;
}

int getType(string type){
	map<string, int>::iterator it;
	it = name.find(type);
	if (it == name.end()){
		name.insert(pair<string, int>(type, intType));
		return intType++;
	}
	else{
		return it->second;
	}
}

int main(){
	int tc;cin >> tc;
	while (tc--){
		int n, budget, p, q;
		cin >> n >> budget;
		string type = "";
		int minq = 1000000005;
		int maxq = 0;
		string temp;

		for (unsigned int i = 0; i<1010; i++)
			components[i].clear();
		
		name.clear();
		intType = 0;
		while (n--){
			cin >> type >> temp >> p >> q;
			parts tempParts;
			tempParts.q = q;
			tempParts.p = p;
			components[getType(type)].push_back(tempParts);
			minq = min(minq, q);
			maxq = max(maxq, q);
		}

		int mid = 0,L = minq,R = maxq;
		while (L<R){
			mid = (L + R + 1) / 2;
			if (valid(mid, budget)){
				L = mid;
			}
			else{
				R = mid - 1;
			}
		}
		cout << L << endl;
	}
	return 0;
}