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
	lli n; cin >> n;
	while (n > 0)
	{
		string s; cin >> s;
		cnt = 0;
		lli mn = INF;
		char c = '.';
		if (s.find('Z') != string::npos){
			cout << 0 << endl;
			goto ola;
		}
		int j;
		for (int i = 0; i < n; i++)
		if (s[i] != '.'){
			c = s[i];
			j = i+1; break;
		}
		for (int i = j; i < n; i++)
		{
			cnt++;
			if (s[i] != '.') {
				if (s[i]!=c)
					mn = min(cnt, mn);// cout << mn <<  "\n";
				cnt=0;
				c = s[i];
			}
			//cout << s[i] << " " << cnt << endl;
		}
		cout << mn << endl;
	ola:
		cin >> n;
	}
}