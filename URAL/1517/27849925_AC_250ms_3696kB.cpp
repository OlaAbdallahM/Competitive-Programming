//       https://v...content-available-to-author-only...e.net/problem/URAL-1517
#include<bits/stdc++.h>
using namespace std;
const int N=int(2e5)+5;
char s[N];
int suff[N],len,rnk[N],newrnk[N],LCP[N];

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
    int t;
    scanf("%d",&t);
    scanf("%s",s);
    s[t]='&';
    scanf("%s",s+t+1);
    buildSuffix_N_log2N();
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