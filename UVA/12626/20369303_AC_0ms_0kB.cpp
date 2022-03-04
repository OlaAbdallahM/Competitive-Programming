#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lli = long long int;
#define mod 10000000000000000007 //1e9+7
#define INF 1000000000 //1e9
#define SZ 200001
void fast() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE //freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif 
}
lli ans, sum,freq,cnt;
int main()
{
	fast();
	lli t; cin >> t;
	while (t--)
	{
		lli frq[26];
		memset(frq, 0, sizeof frq);
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++)frq[s[i] - 'A']++;
		cout << min(min(min(min(min(frq['A' - 'A'] / 3, frq['R' - 'A'] / 2),
			frq['G' - 'A']), frq['T' - 'A']), frq['I' - 'A']), frq['M' - 'A']) << endl;
	}
}
