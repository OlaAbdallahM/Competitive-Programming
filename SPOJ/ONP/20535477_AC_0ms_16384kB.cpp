#include<bits/stdc++.h>
using lli =    long long int ; using namespace std;
bool isprime(lli n); lli gcd(lli a, lli  b);
lli lcm(lli n, lli m); lli fact(lli n);
double dgr(double a); int fixMod(int a, int b);
long long  ncr(int n, int r); void fast();
lli maxSubArraySum(lli a[], lli size);
lli compute(lli h, lli n, int cur);
lli const L = 0;
#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SZ 200010
string infix2postfix(const string exp)
{
	stack<char>my_stack;
	string postExp;
	char ch;
	char ch2;
	for (unsigned int i = 0; i < exp.size(); i++)
	{
		ch = exp[i];
		if (ch == '(')
			my_stack.push(ch);
		else if (ch == ')')
		{
			ch2 = my_stack.top();
			while (ch2 != '(')
			{
				postExp.push_back(my_stack.top());
				my_stack.pop();
				ch2 = my_stack.top();
			}
			my_stack.pop();
		}
		else if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/')||(ch=='^'))
		{
			if (my_stack.empty())
				my_stack.push(ch);
			else
			{
				ch2 = my_stack.top();
				while (((ch2 == '*') || (ch2 == '/') || (ch2 == '+') || (ch2 == '-')||(ch2=='^')) && ((ch == '+') || (ch == '-')))
				{
					postExp.push_back(my_stack.top());
					my_stack.pop();
					if (my_stack.empty())
						break;
					ch2 = my_stack.top();
 
				}
				my_stack.push(ch);
			}
		}
		else postExp.push_back(ch);
	}
	if (!my_stack.empty())
	{
		while (1)
		{
			postExp.push_back(my_stack.top());
			my_stack.pop();
			if (my_stack.empty())
				break;
		}
	}
	return postExp;
}
int main()
{
	fast();
	lli t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		cout << infix2postfix(s) << endl;
	}
}
 
	void fast() {
		ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE //freopen("input.in", "r", stdin); //freopen("output.out", "w", stdout);
#endif 
	}