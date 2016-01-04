#include<bits/stdc++.h>

using namespace std;

#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)

#define plln(n) printf("%lld\n",n)

#define s3ll(n1,n2,n3) scanf("%ld%ld%ld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

typedef long long LL;

#define MOD 1000000007
#define mx 1000600

LL cnt[mx],a[mx],b[mx],M[mx],n;

void update(LL idx,LL val)
{
    while(idx<=n)
    {
        cnt[idx]+=val;
        idx+=( idx & -idx );
    }
}

LL query(LL idx)
{
    LL sum=0;
    while(idx>0)
    {
        sum+=cnt[idx];
        idx-=( idx & -idx );
    }
    return sum;
}

int main()
{
    LL t,i,j,k,ans;
    s2ll(n,k);
    memset(cnt,0,sizeof(cnt));
    vector< pair<LL,LL> > v;
    LL pre[n+5];
    ans=(n*(n+1))/2;
    pre[-1]=0;
    rep(i,n){
        sll(a[i]);
        b[i]=a[i]-k;
        pre[i]=pre[i-1]+b[i];
        if(pre[i]<0) ans--;
        v.push_back(make_pair(pre[i],i+1));
    }
    sort(v.begin(),v.end());
    LL x=1;
    for(i=0;i<n;i++){
        if(i>0){ if(v[i].first>v[i-1].first) x++;}
        M[v[i].second]=x;
    }
    for(i=n;i>=1;i--)
    {
        ans-=query(M[i]-1);
        update(M[i],1);
    }
    plln(ans);
    return 0;
}

