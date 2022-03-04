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
	cin >> n;
	while (n--)
	{
		vector<long long>a(3);
		cin >> a[0] >> a[1] >> a[2];
		sort(a.begin(), a.end());
		if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])
			cout << "YES" << endl;
		else cout << "NO" << endl;
	//cout << endl;

	}
	//system("pause");
}
