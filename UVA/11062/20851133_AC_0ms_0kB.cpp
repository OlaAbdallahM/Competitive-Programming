#define _CRT_SECURE_NO_WARNINGS
//               Allah_Almost3aan        *{فَصَبْرٌ جَمِيلٌ وَاللَّهُ الْمُسْتَعَانُ }*
//                  *{ربى..  كنْ لىِ خيرَ مدبر فإنى لا احسنُ التدبير}*
#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define endl "\n"
#define mod 100000007 //1e9+7
#define INF 1000000000 //1e9
#define SZ 2000001
void fast() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE //freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif 
}
long long  ncr(int n, int r)
{
	if (r > n - r)r = n - r; long long  ans = 1;
	lli j = 2;
	for (int i = n - r + 1; i <= n; i++){
		ans *= i;
		while (!(ans%j) && j <= r){
			ans /= j; j++;
		}
	}
	return ans;
}
lli gcd(lli a, lli  b)
{
	if (b == 0)return a;
	else
		return gcd(b, a%b);
}
lli lcm(lli n, lli m)
{
	return n*m / gcd(n, m);
}
bool isprime(lli n)
{
	if (n == 0 || n == 1)return 0;
	if (n == 2 || n == 3) return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	for (int i = 5; i <= sqrt(n); i += 6) if (n%i == 0 || n % (i + 2) == 0)
		return 0;
	return 1;
}
bool vis[SZ];
lli len, sp[SZ];
void Sieve(){
	for (int i = 2; i < SZ; i += 2)	sp[i] = 2;
	for (lli i = 3; i < SZ; i += 2)
	{
		if (!vis[i])
		{
			sp[i] = i;
			for (lli j = i; (j*i) <SZ; j += 2)
			{
				if (!vis[j*i])
				{
					vis[j*i] = true;
					sp[j*i] = i;
				}
			}
		}
	}
}
lli pow_md(lli a, lli n, lli md)
{
	lli ans = 1;

	for (; n; n >>= 1)
	{
		if (n & 1)
			ans = (ans * 1ll * a) % md;

		a = (a * 1ll * a) % md;
	}

	return ans;
}
bool ok[SZ];
lli cnt, sum,mn,ans, mx,frq[26];
map<lli, lli>mp;
int main()
{
	fast();
	lli q; //cin >> q;
		q = 1;
	while (q--)
	{
		string s, ss, temp = "";
		set<string>st;
		while (cin >> s)
		{
			if (s.empty()) continue;
			if (s[s.size() - 1] == '-')
				s.erase(s.size() - 1, 1);   // s=s.substr(0,s.size()-1);
			else s += ' ';
			ss += s;
		}

		for (int i = 0; i < ss.size(); i++)
		{
			if (ss[i] >= 'A'&&ss[i] <= 'Z')        ss[i] = tolower(ss[i]);  //ss[i] += 32;
			if (isalpha(ss[i]) || ss[i] == '-')
				temp += ss[i];
			else
			{
				if(temp.size()>0) st.insert(temp);
				temp.clear();
			}
		}
		if (temp.size()>0) st.insert(temp);
		for (auto i : st) cout << i << endl;

	}
}
