#define _CRT_SECURE_NO_WARNINGS
//   Allah_Almost3aan
#include<bits/stdc++.h>
//#include <unordered_map>
using namespace std;
 #define ll  long long
//#define MOD 1e9+7
#define fnt 0x3f3f3f3f
#define ed '\n'
#define ff first
#define ss second
#define sz(a) a.size()
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define RT(v)return cout<<v<<ed,0
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
const ll OO = 1e18;
const int N=1e5+5;
void fast() {
ios::sync_with_stdio(false);
cin.tie(0); cout.tie(0);}
//**************************************
int n, c[1<<10];
void solve(int x) {
    ll res = 0, xx = 1;
    //   cout<<x<<' ';
    for (int i = n - 1; i >= 0; i--) {
        res += c[i] * xx;
        xx *= x;
    }
    printf("%lld", res);
}

int main(){
	//fast();
 int len, k, x;
    char s[1<<10];
    while (gets(s)) {
        len = strlen(s), k = 0;
        n = 0;
        while (k < len) {
            while (k < len && s[k] == ' ') k++;
            if (k < len) {
                sscanf(s + k, "%d", &c[n++]);
                while (k < len && s[k] != ' ') k++;
            }
        }
        
        gets(s);
        len = strlen(s), k = 0;
        bool space = false;
        while (k < len) {
            while (k < len && s[k] == ' ') k++;
            if (k < len) {
                sscanf(s + k, "%d", &x);
                if (space) printf(" "); space = true;
                solve(x);
                while (k < len && s[k] != ' ') k++;
            }
        }
        printf("\n");
    }
return 0;
}
