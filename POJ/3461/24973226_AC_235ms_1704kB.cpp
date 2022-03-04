#include<iostream>
#include<string>
using namespace std;
int LP[10010];
string s, t;
void failure_function()
{
	for (int k = 0, i = 1; i <s.size(); i++)
	{
		while (k>0 && s[k] != s[i])
			k = LP[k - 1];
		if (s[k] == s[i])
			LP[i] = ++k;
		else LP[i] = k;
	}
}
int KMP()
{
	int ans = 0;
	for (int i = 0, k = 0; i < t.size(); i++)
	{
		while (k>0 && s[k] != t[i])
			k = LP[k - 1];
		if (s[k] == t[i])
			k++;
		if (k == s.size())
		{
			ans++;
			k = LP[k-1];
		}
	}
	return ans;
}
int main()
{
	int q; cin >> q;
	while (q--)
	{
		cin >> s >> t;
		failure_function();
		cout<<KMP()<<endl;
	}
}
