#include <bits/stdc++.h>
using namespace std;
//using lli = long long int;
int main()
{
	/***  بسم الله الرحمن الرحيم   ***/
	//cout << fixed << setprecision(5);
	//file();
	//fast();
	string s; cin >> s;
	long long n; 
	long long a, b;
	cin >> n;
	//n = 1;
	while (n--)
	{
		string t; cin >> t;
		if (t == "replace")
		{
			cin >> a>>b; string r; cin >> r;
			long long j = 0;
			for (int i = 0; i < s.size(); i++)
			{
				if (i == a&&a<=b)
				{
					s[i] = r[j];
					a++;
						j++;
			   }	
			}
		}
		else if (t == "reverse")
		{
			cin >> a >> b;
			string x1, x2, x3;
			for (int i = 0; i < s.size(); i++)
			{
				if (i<a) x1 += s[i];
				else if (i >= a&&i <= b) x2 += s[i];
				else if (i>b)x3 += s[i];
			}
			x2 = string(x2.rbegin(), x2.rend());
			s = x1 + x2 + x3;
		}
		else if (t == "print")
		{
			cin >> a >> b;
			for (int i = a; i <= b; i++)
				cout << s[i];
			cout << endl;
		}
	}
//	system("pause");
}