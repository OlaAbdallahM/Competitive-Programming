
#include <iostream>
#include <string>
#include<vector>
#include <math.h>
#include<map>
#include<algorithm>
using namespace std;

#define sz(a)a.size()
#define vi vector<int>


map<vi,int>mp;
string s;
int cont;

int hsh(int l, int r){
	vi v;
	v.push_back(0);
	int aux = 0;
	for (int i = l, x = l; i <= r; ++i){
		if (s[i] == '0') ++aux;
		else --aux;
		if (aux == 0){
			v.push_back(hsh(x + 1, i - 1));
			x = i + 1;
		}
	}
	if (sz(v)> 1) sort(v.begin() + 1, v.end());
	v.push_back(1);
	if (mp.find(v) == mp.end()) mp[v] = cont++;
	return mp[v];
}

int main(){
	
	int t; cin >> t;
	while (t--){
		string s1, s2; cin >> s1 >> s2;
		if (sz(s1) != sz(s2)){
			cout << "different\n";
			continue;
		}
			cont = 2;
			mp.clear();
			s = s1;
			int x= hsh(0, sz(s) - 1);
			s = s2;
			int y = hsh(0, sz(s) - 1);
			cout << (x == y ? "same\n" : "different\n");
	}
}