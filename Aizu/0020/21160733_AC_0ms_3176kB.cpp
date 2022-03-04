#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	/***  بسم الله الرحمن الرحيم   ***/
	//cout << fixed << setprecision(5);
	//file();
	//fast();

	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i])) s[i] -= 32;
		cout << s[i];
	}
cout<<endl;
	//system("pause");
}
