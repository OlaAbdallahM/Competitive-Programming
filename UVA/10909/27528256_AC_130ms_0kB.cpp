#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll =  long long;
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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1<<10;
const ll mod = 1e9 + 7;
 
const int MAX = 4194304;
bool is_lucky[N + 1];
int interval[MAX + 9], gs = 0, ge = N - 1;
 
int insert(int val, int s = gs, int e = ge, int i = 1)
{
	interval[i]++;
	if (s == e)return interval[i] - 1;
	if ((s + e) / 2 >= val)
		return insert(val, s, (s + e) / 2, 2 * i);
	return interval[2 * i] + insert(val, (s + e) / 2 + 1, e, 2 * i + 1);
}
 
int get(int kth, int s = gs, int e = ge, int i = 1)
{
	if (s == e) return s;
	if (interval[2 * i] >= kth)
		return get(kth, s, (s + e) / 2, 2 * i);
	return get(kth - interval[2 * i], (s + e) / 2 + 1, e, 2 * i + 1);
}
 
int delet(int kth, int s = gs, int e = ge, int i = 1)
{
	interval[i]--;
	if (s == e) return s;
	if (interval[2 * i] >= kth) return delet(kth, s, (s + e) / 2, 2 * i);
	return delet(kth - interval[2 * i], (s + e) / 2 + 1, e, 2 * i + 1);
}
 
int main() {
	fast;
	for (int i = 1; i < N; i += 2)
		insert(i);
	is_lucky[1] = 1;
	int available = 1e6;
	for (int i = 2; i <= available; i++)
	{
		int next = 1, removed = 0, term = get(i);
		is_lucky[term] = 1;
		while (term*next - removed <= available)
		{
			delet(term*next - removed);
			next++, removed++, available--;
		}
	}
	int n;
	while (cin >> n)
	{
		int md = n / 2;
		bool found = false;
		if (n % 2 == 0)
		for (int k = md; k > 0; k--)
		{
			if (is_lucky[k] && is_lucky[n - k])
			{
				cout << n << " is the sum of " << k << " and " << n - k << ".\n";
				found = true;
				break;
			}
		}
		if (!found)
			cout << n << " is not the sum of two luckies!\n";
	}
}