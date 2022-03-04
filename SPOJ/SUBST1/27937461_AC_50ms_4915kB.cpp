#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll =  long long;
using ld = long double;
const ll OO = 1e18;
#define ed '\n'
#define F first
//#define S second
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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;

int str[N]; //input
int rnk[N], pos[N]; //output
int cnt[N], nxt[N]; //internal
bool bh[N], b2h[N];

bool smaller_first_char(int a, int b){
	return str[a] < str[b];
}

void SuffixSort(int n){
	//sort suffixes according to their first character
	for (int i = 0; i<n; ++i)pos[i] = i;
	
	sort(pos, pos + n, smaller_first_char);
	//{pos contains the list of suffixes sorted by their first character}

	for (int i = 0; i<n; ++i){
		bh[i] = i == 0 || str[pos[i]] != str[pos[i - 1]];
		b2h[i] = false;
	}

	for (int h = 1; h < n; h <<= 1){
		//{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
		int buckets = 0;
		for (int i = 0, j; i < n; i = j){
			j = i + 1;
			while (j < n && !bh[j]) j++;
			nxt[i] = j;
			buckets++;
		}
		if (buckets == n) break; // We are done! Lucky bastards!
		//{suffixes are separted in buckets containing strings starting with the same h characters}

		for (int i = 0; i < n; i = nxt[i]){
			cnt[i] = 0;
			for (int j = i; j < nxt[i]; ++j){
				rnk[pos[j]] = i;
			}
		}

		cnt[rnk[n - h]]++;
		b2h[rnk[n - h]] = true;
		for (int i = 0; i < n; i = nxt[i]){
			for (int j = i; j < nxt[i]; ++j){
				int s = pos[j] - h;
				if (s >= 0){
					int head = rnk[s];
					rnk[s] = head + cnt[head]++;
					b2h[rnk[s]] = true;
				}
			}
			for (int j = i; j < nxt[i]; ++j){
				int s = pos[j] - h;
				if (s >= 0 && b2h[rnk[s]]){
					for (int k = rnk[s] + 1; !bh[k] && b2h[k]; k++) b2h[k] = false;
				}
			}
		}
		for (int i = 0; i<n; ++i){
			pos[rnk[i]] = i;
			bh[i] |= b2h[i];
		}
	}
	for (int i = 0; i<n; ++i){
		rnk[pos[i]] = i;
	}
}
// End of suffix array algorithm

// Algorithm GetHeight
// input: A text A and its suffix array Pos
//    1 for i:=1 to n do
//    2     Rank[Pos[i]] := i
//    3 od
//    4 h:=0
//    5 for i:=1 to n do
//    6     if Rank[i] > 1 then
//    7        k := Pos[Rank[i]-1]
//    8        while A[i+h] = A[j+h] do
//    9           h := h+1
//    10       od
//    11       Height[Rank[i]] := h
//    12       if h > 0 then h := h-1 fi
//    13    fi
//    14 od

int height[N];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0
void getHeight(int n){
	for (int i = 0; i<n; ++i) rnk[pos[i]] = i;
	height[0] = 0;
	for (int i = 0, h = 0; i<n; ++i){
		if (rnk[i] > 0){
			int j = pos[rnk[i] - 1];
			while (i + h < n && j + h < n && str[i + h] == str[j + h]) h++;
			height[rnk[i]] = h;
			if (h > 0) h--;
		}
	}
}

string s;

void solve(){
	int n = sz(s);
	for (int i = 0; i<n; ++i) str[i] = s[i];
	SuffixSort(n);
	getHeight(n);
	long long ans = 0;
	for (int i = 0; i<n; ++i){
		ans += n - pos[i] - height[i];
	}
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> s;
		solve();
	}
	return 0;
}
