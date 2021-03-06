#include<bits/stdc++.h>

using namespace std;

#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)

#define plln(n) printf("%lld\n",n)

#define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

typedef long long LL;

#define mod 5000000
#define mx 100005

LL bit[mx],a[mx],b[mx],M[mx],n,k;

void update(LL idx,LL val)
{
    while(idx<=mx)
    {
        bit[idx]=(bit[idx]+val)%mod;
        idx+=( idx & -idx );
    }
}

LL query(LL idx)
{
    LL sum=0;
    while(idx>0)
    {
        sum=(sum+bit[idx])%mod;
        idx-=( idx & -idx );
    }
    return sum;
}

void solve()
{
    LL i,j;
    rep(i,k)
    {
        memset(bit,0,sizeof(bit));
        rep(j,n){
            update(a[j],b[j]);
            b[j]=query(a[j]-1);
        }
    }
    plln(query(mx));
}

int main()
{
    LL t,i,j,ans;
    s2ll(n,k);
    rep(i,n){ sll(a[i]);a[i]++;b[i]=1;}
    solve();
    return 0;
}

