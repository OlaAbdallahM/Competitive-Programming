#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e18;
#define ed '\n'
#define EPS 1e-12
#define PI acos(-1.0)
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
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e8 + 7, N = 1e7;

int n, h;
int f[27], d[27], t[27];
int dp[26][200][200];
int path[27];

int rec(int idx, int rem, int taken){
	if (idx == n) // base case
		return 0;
	int &ret = dp[idx][rem][taken];
	if (ret != -1)
		return ret;
	int choice1 = 0, choice2 = 0; // we have 2 choices, either we stay for another 5 minutes or we leave

	if (rem > 0){ // we can stay for another 5 minutes if we still have time more than 1 ( 1 here mean 5 minutes )
		int expected_fish = f[idx] - d[idx] * taken;  // now we get number of fish (f[i]) - the rate of decrease*the number of 5 minutes we spent here
		if (expected_fish < 0) // if there's no more fish then expected_fish = 0 not negative value
			expected_fish = 0;
		choice1 = rec(idx, rem - 1, taken + 1) + expected_fish; // now we stay at the same place but decrease time by 5 minutes ( 5 minutes here mean 1 ) and we increase the number of time we spent here
	}
	if (rem >= t[idx]) // we can leave to second lake if we have time >= time of traveling
		choice2 = rec(idx + 1, rem - t[idx], 0); // move with idx, decrease rem by amount time for traveling, and we start taken time we spent time there on 0
	return ret = max(choice1, choice2); // we take the max
}


void build_output(int idx, int rem, int taken){ // build output with the same recursion function
	if (idx == n) // base case
		return;
	int choice1 = -1, choice2 = -1; // initialize the two choices to -1 ( not 0 because we might have some stored states with 0 values )

	if (rem > 0){ // same as recursion function
		int expected_fish = f[idx] - d[idx] * taken;
		if (expected_fish < 0)
			expected_fish = 0;
		choice1 = rec(idx, rem - 1, taken + 1) + expected_fish;
	}
	if (rem >= t[idx]) // same as recursion function
		choice2 = rec(idx + 1, rem - t[idx], 0);

	int optimal = rec(idx, rem, taken); // now we get the max result we got from the recursion function

	if (optimal == choice1){ // if the max result was from the first choice
		path[idx]++; // then we stayed here for 5 minutes
		build_output(idx, rem - 1, taken + 1); // and then we build the output for the next states as we stayed for another 5 minutes
	}
	else if (choice2 != -1){ // if the max result was from the second choice
		build_output(idx + 1, rem - t[idx], 0); // we didn't stay at this index so we leave it as 0 and build for next lake if we can go to it
	}
	return;
}

int main(){
	//fast;
	bool first = 1; // indicate if it's the first case
	while (cin >> n){
		if (!n) // end of input when n = 0
			break;
		if (!first)
			puts("");
		memset(dp, -1, sizeof(dp));
		memset(path, 0, sizeof(path));
		memset(t, 0, sizeof(t));

		first = 0;
		cin >> h;
		for (int i = 0; i<n; i++)
			cin >> f[i];

		for (int i = 0; i<n; i++)
			cin >> d[i];

		for (int i = 0; i<n - 1; i++)
			cin >> t[i];

		int res = rec(0, h * 12, 0); // first solve the solve the problem

		build_output(0, h * 12, 0); // then build the output

		for (int i = 0; i<n - 1; i++) // output the path we made
			cout << path[i] * 5 << ", ";
		cout << path[n - 1] * 5 << endl;

		cout << "Number of fish expected: " << res << endl;
	}

}