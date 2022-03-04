#include <bits/stdc++.h>
using namespace std;

struct node;
extern node* empty;
struct node
{
	int freq;
	node *l,*r;
	node()
	{
		freq=0;
		l=r=this;
	}
	node(int f,node *lft=empty,node *rt=empty)
	{
		freq=f;
		l=lft;
		r=rt;
	}
};


node *empty=new node;
vector<vector<int> > adj;
vector<int> node2ind,ind2node,depth;
vector<node *> roots,parents;

int value[int(1e5)+5];
int n,m;
int spt[int(2e5)+5][20];
int lgs[int(2e5)+5];



node *insert(node *root,int val,int nst=INT_MIN,int nen=INT_MAX)
{
	if(val<nst||val>nen)
		return root;
	if(nst==nen)
		return new node(root->freq+1);
	int md=nst+(nen-0ll-nst)/2;
 
	node *rt1=insert(root->l,val,nst,md);
	node *rt2=insert(root->r,val,md+1,nen);
	return new node(rt1->freq+rt2->freq,rt1,rt2);
}

int query(node *rtu,node *rtv,node *rtLCA,node *rtp,int k,int nst=INT_MIN,int nen=INT_MAX)
{
	if(nst==nen)
		return nst;
	int lsz=rtu->l->freq+rtv->l->freq-rtLCA->l->freq-rtp->l->freq;
	int md=nst+(nen-0ll-nst)/2;
	if(k<=lsz)
		return query(rtu->l,rtv->l,rtLCA->l,rtp->l,k,nst,md);
	else
		return query(rtu->r,rtv->r,rtLCA->r,rtp->r,k-lsz,md+1,nen);
}
void init()
{
	adj.resize(n+1);
	depth.resize(n+1);
	node2ind.resize(n+1);
	roots.resize(n+1);
	parents.resize(n+1);
}

void dfs(int u,int dpth=0,node *parent=empty,int p=0)
{
	node2ind[u]=ind2node.size();
	ind2node.push_back(u);
	parents[u]=parent;
	roots[u]=insert(parent,value[u]);
	depth[u]=dpth;
	for(int v:adj[u])
	{
		if(v==p)
			continue;
		dfs(v,dpth+1,roots[u],u);
		ind2node.push_back(u);
	}
}

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
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",value+i);
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
	while(m--)
	{
		scanf("%d %d %d",&u,&v,&k);
		int lca=SPTLCA(u,v);
		int res=query(roots[u],roots[v],roots[lca],parents[lca],k);
		printf("%d\n",res);
	}
	return 0;
}