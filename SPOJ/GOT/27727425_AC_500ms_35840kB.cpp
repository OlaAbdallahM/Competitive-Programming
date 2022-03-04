#include <bits/stdc++.h>
using namespace std;
// https://w...content-available-to-author-only...j.com/problems/GOT/
int n,a[int(1e5)+5],q,qs[int(2e5)+5],qe[int(2e5)+5],qlca[int(2e5)+5],qk[int(2e5)+5],qi[int(2e5)+5],s,e,qa[int(2e5)+5];
bool occ[int(1e5)+5];
int freq[int(1e6)+5];
vector<vector<int> > adj;
vector<int> node2ind,ind2node,depth,st,et,dfsorder;
void add(int val)
{
    freq[val]++;
}
void rem(int val)
{
    freq[val]--;
}
void change(int val)
{
    if(occ[val]^=1)
        add(a[val]);
    else
        rem(a[val]);
}
void update(int cur)
{
    while(e<=qe[cur])
        change(dfsorder[e++]);
    while(s>qs[cur])
        change(dfsorder[--s]);
    while(e>qe[cur]+1)
        change(dfsorder[--e]);
    while(s<qs[cur])
        change(dfsorder[s++]);
}
void mo()
{
    int sq=sqrt(dfsorder.size());
    sort(qi,qi+q,[sq](int a,int b){return make_pair(qs[a]/sq,qe[a])<make_pair(qs[b]/sq,qe[b]);});
    s=e=0;
    for(int i=0;i<q;i++)
    {
        int cur=qi[i];
        update(cur);
        add(a[qlca[cur]]);
        qa[cur]=freq[qk[cur]]!=0;
        rem(a[qlca[cur]]);
    }
}
void init()
{
    adj.clear();
    adj.resize(n+1);
    depth.resize(n+1);
    node2ind.resize(n+1);
    st.resize(n+1);
    et.resize(n+1);
    dfsorder.clear();
    ind2node.clear();
    memset(freq,0,sizeof(freq));
    memset(occ,0,sizeof(occ));
}
void dfs(int u,int dpth=0,int p=0)
{
    node2ind[u]=ind2node.size();
    ind2node.push_back(u);
    depth[u]=dpth;
    st[u]=dfsorder.size();
    dfsorder.push_back(u);
    for(int v:adj[u])
    {
        if(v==p)
            continue;
        dfs(v,dpth+1,u);
        ind2node.push_back(u);
    }
    et[u]=dfsorder.size();
    dfsorder.push_back(u);
}
int lgs[int(2e5)+5];
int spt[int(2e5)+5][20];
void buildSpt()
{
    lgs[0]=-1;
    for(int i=0;i<ind2node.size();i++)
    {
        spt[i][0]=i;
        lgs[i+1]=lgs[i]+!(i&(i+1));
    }
    for(int j=1;(1<<j)<=ind2node.size();j++)
    {
        for(int i=0;i+(1<<j)<=ind2node.size();i++)
        {
            int a=spt[i][j-1];
            int b=spt[i+(1<<(j-1))][j-1];
            spt[i][j]=(depth[ind2node[a]]<depth[ind2node[b]])?a:b;
        }
    }
}

int SPTRMQ(int a,int b)
{
    int sz=b-a+1;
    int lg=lgs[sz];
    a=spt[a][lg];
    b=spt[b-(1<<lg)+1][lg];
    return (depth[ind2node[a]]<depth[ind2node[b]])?a:b;
}
int SPTLCA(int u,int v)
{
    int a=node2ind[u];
    int b=node2ind[v];
    if(a>b)
        swap(a,b);
    return ind2node[SPTRMQ(a,b)];
}

int main() {
    while(~scanf("%d %d",&n,&q))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        init();
        int u,v,k;
        for(int i=1;i<n;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        buildSpt();
        for(int i=0;i<q;i++)
        {
            qi[i]=i;
            scanf("%d %d %d",&u,&v,&k);
            qk[i]=k;
            if(st[u]>st[v])
                swap(u,v);
            qlca[i]=SPTLCA(u,v);
            if(qlca[i]==u)
                qs[i]=st[u]+1,qe[i]=st[v];
            else
                qs[i]=et[u],qe[i]=st[v];
        }
        mo();
        for(int i=0;i<q;i++)
            printf("%s\n",(qa[i]?"Find":"NotFind"));
    }

    return 0;
}