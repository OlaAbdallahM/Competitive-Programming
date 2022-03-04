#include<bits/stdc++.h>
#define ll long long
using namespace std;
int getbit(int n,int idx){return ((n>>idx)&1);}
int clearbit(int n,int idx){return (n&~(1<<idx));}
int n,m;int c[20][20];
int x[20],y[20],dp[1<<17];
int cntbit(int n)
{
    int res = 0;
    while(n)
    {
        if(n&1)
            res++;
        n>>=1;
    }
    return res;
}
int solve(int mask)
{
    if(n-cntbit(mask)>=m)
        return 0;
    int &rt = dp[mask];
    if(~rt)
        return rt;
    vector<int>v;
    for(int i=0;i<n;i++)
        if(getbit(mask,i))
        v.push_back(i);
    rt = 100;
    for(int i=0;i<v.size();i++)
    for(int j=i+1;j<v.size();j++)
        rt = min(rt,1+solve(mask&c[v[i]][v[j]]));
    if(rt==100)rt = 1;
    return rt;
}
void build()
{
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        if(i!=j)
        {
            int temp = (1<<n) - 1;
            temp = clearbit(temp,i);
            temp = clearbit(temp,j);
            for(int k=0;k<n;k++)
            {
                if(i!=k&&j!=k)
                {
                    int x1 = x[j] - x[i];
                    int y1 = y[j] - y[i];
                    int x2 = x[k] - x[i];
                    int y2 = y[k] - y[i];
                    if(y2*x1==y1*x2)
                        temp = clearbit(temp,k);
                }
            }
            c[i][j] = temp;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        memset(c,0,sizeof c);
        build();
        memset(dp,-1,sizeof dp);
        cout<<"Case #"<<k<<":\n";
        cout<<solve((1<<n)-1)<<'\n';
        if(k<t)cout<<'\n';
    }
    return 0;
}