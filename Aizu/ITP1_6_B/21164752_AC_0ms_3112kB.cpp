#include <bits/stdc++.h>
using namespace std;
//using lli = long long int;
int main()
{
	/***  بسم الله الرحمن الرحيم   ***/
	//cout << fixed << setprecision(5);
	//file();
	//fast();
	map<pair<char, int>, bool>mp;
	for (int i = 1; i <= 13; i++)
	{
		mp[{'H', i}] = true;
	}
	for (int i = 1; i <= 13; i++)
	{
		mp[{'S', i}] = true;
	}
	for (int i = 1; i <= 13; i++)
	{
		mp[{'C', i}] = true;
	}
	for (int i = 1; i <= 13; i++)
	{
		mp[{'D', i}] = true;
	}
	long long n; 
	cin >> n;
	//n = 1;
	while (n--)
	{
		char c; cin >> c;
		int a; cin >> a;
		mp[{c, a}] = false;
	}
	vector<pair<int, char> >v;
	for (int i = 1; i <= 13; i++)
	{
		if (mp[{'H', i}])
			v.push_back({ i, 'H' });
	}
	for (int i = 1; i <= 13; i++)
	{
		if (mp[{'S', i}])
			v.push_back({ i, 'S' });
	}
	for (int i = 1; i <= 13; i++)
	{
		if (mp[{'C', i}])
			v.push_back({ i, 'C' });
	}
	for (int i = 1; i <= 13; i++)
	{
		if (mp[{'D', i}])
			v.push_back({ i, 'D' });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second=='S')
		cout << v[i].second << " " << v[i].first << endl;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second == 'H')
			cout << v[i].second << " " << v[i].first << endl;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second == 'C')
			cout << v[i].second << " " << v[i].first << endl;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second == 'D')
			cout << v[i].second << " " << v[i].first << endl;
	}
//	system("pause");
}