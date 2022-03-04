#include<bits/stdc++.h>
using namespace std;
const int N=int(2e5)+5,alpha=128;
char s[N];
int suff[N],len,rnk[N],newrnk[N],LCP[N],newSuff[N],bst[N];

void buildSuffix_N2_logN()
{
    for(len=0;!len||s[len-1];++len)
        suff[len]=len;
    sort(suff,suff+len,[](int a,int b){ return strcmp(s+a,s+b)<0;});
}
void buildSuffix_N_log2N()
{
    for(len=0;!len||s[len-1];++len)
    {
        suff[len] = len;
        rnk[len]=s[len];
    }
    int cur=1;
    do
    {
        auto cmp=[cur](int a,int b){return rnk[a]<rnk[b]||rnk[a]==rnk[b]&&rnk[a+cur]<rnk[b+cur];};
        sort(suff,suff+len,cmp);
        for(int i=1;i<len;++i)
            newrnk[i]=newrnk[i-1]+cmp(suff[i-1],suff[i]);
        for(int i=0;i<len;++i)
            rnk[suff[i]]=newrnk[i];
        cur<<=1;
    }while(newrnk[len-1]!=len-1);
}
void buildSuffix_N_logN()
{
    int *head=newSuff,*nxt=newrnk;
    memset(head,-1,alpha*sizeof(head[0]));
    for(len=0;!len||s[len-1];++len)
    {
        suff[len] = len;
        nxt[len]=head[s[len]];
        head[s[len]]=len;
    }
    int p=0,b=-1;
    for(int i=0;i<alpha;i++)
    {
        if(head[i]==-1)
            continue;
        bst[++b]=p;
        for(int j=head[i];~j;j=nxt[j])
        {
            rnk[j]=b;
            suff[p++]=j;
        }
    }
    int cur=1;
    newrnk[0]=0;
    newSuff[0]=suff[0];
    do
    {
        auto cmp=[cur](int a,int b){return rnk[a]<rnk[b]||rnk[a]==rnk[b]&&rnk[a+cur]<rnk[b+cur];};

        for(int i=0;i<len;++i)
        {
            int j=suff[i]-cur;
            if(j<0)
                continue;
            newSuff[bst[rnk[j]]++]=j;
        }

        for(int i=1;i<len;++i)
        {
            suff[i]=newSuff[i];
            bool cmpres=cmp(suff[i - 1], suff[i]);
            newrnk[i] = newrnk[i - 1] + cmpres;
            if(cmpres)
                bst[newrnk[i]]=i;
        }
        for(int i=0;i<len;++i)
            rnk[suff[i]]=newrnk[i];
        cur<<=1;
    }while(newrnk[len-1]!=len-1);
}
void build_LCP()
{
    int cnt=0;
    for(int i=0;s[i];++i)
    {
        int j=suff[rnk[i]-1];

        while(s[i+cnt]==s[j+cnt])
            cnt++;
        LCP[rnk[i]]=cnt;
        if(cnt)cnt--;
    }
}
int main() {
    /*strcpy(s,"abracadabra");
    buildSuffix_N_logN();
    for(int i=0;i<len;i++)
        printf("%s\n",s+suff[i]);*/
    int t;
    scanf("%d",&t);
    scanf("%s",s);
    s[t]='&';
    scanf("%s",s+t+1);
    buildSuffix_N_logN();
    build_LCP();
    int mx=-1,pos;
    for(int i=1;i<len;i++)
        if((suff[i]<t)!=(suff[i-1]<t))
        {
            if(LCP[i]>mx)
            {
                mx = LCP[i];
                pos=suff[i];
            }
        }
    s[mx+pos]=0;
    puts(s+pos);
    return 0;
} 