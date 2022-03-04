#define _CRT_SECURE_NO_WARNINGS
//   Allah_Almost3aan
#include<bits/stdc++.h>
//#include <unordered_map>
using namespace std;
#define  ll  long long
//const ll OO = 1e18;
#define MOD 1e9+7
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
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}const int NumNumbers = 5;
const double eps = 0.5;

int numbers[NumNumbers];

bool Possible(int total, int pos)
{
    if (pos == NumNumbers)
        return total == 23;

    int num = numbers[pos];

    return Possible(total + num, pos + 1)
        || Possible(total - num, pos + 1)
        || Possible(total * num, pos + 1);
}

void ReadNumbers()
{
    for (int i = 0; i < NumNumbers; ++i)
        cin >> numbers[i];
}

bool NotAllZero()
{
    for (int i = 0; i < NumNumbers; ++i)
        if (numbers[i])
            return true;

    return false;
}int main(){
	fast();
	while (ReadNumbers(), NotAllZero())
    {
        sort(numbers, numbers + NumNumbers);
        bool possible = false;
        do {
            possible = Possible(numbers[0], 1);
            if (possible)
                break;
        } while (next_permutation(numbers, numbers + NumNumbers));

        if (possible)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }

  return 0;
}
