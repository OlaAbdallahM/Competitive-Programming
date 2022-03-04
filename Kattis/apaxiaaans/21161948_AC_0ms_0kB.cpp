#include <bits/stdc++.h>
using namespace std;
//using lli = long long int;
int main()
{
	/***  بسم الله الرحمن الرحيم   ***/
	//cout << fixed << setprecision(5);
	//file();
	//fast();

	long long n; 
	//cin >> n;
	n = 1;
	while (n--)
	{
		string s; cin >> s;
		cout << s[0];
		char temp = s[0];
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == temp) continue;
			cout << s[i];
			temp = s[i];
		}
		cout << endl;
	}
	//system("pause");
}