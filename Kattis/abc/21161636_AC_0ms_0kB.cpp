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
		vector<long long>a(3);
		cin >> a[0] >> a[1] >> a[2];
		sort(a.begin(), a.end());
		long long A = a[0],B=a[1],C=a[2];
		string s; cin >> s;
		for (int i = 0; i < s.size()-1; i++)
		{
			if (s[i] == 'A')cout << A << " ";
			else if (s[i] == 'B') cout << B << " ";
			else if (s[i] == 'C') cout << C << " ";
		}
		if (s[s.size() - 1] == 'A')cout << A << endl;
		else if (s[s.size() - 1] == 'B') cout << B << endl;
		else if (s[s.size() - 1] == 'C') cout << C<<endl;
	}
	//system("pause");
}