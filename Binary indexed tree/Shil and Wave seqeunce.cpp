#include<bits/stdc++.h>

using namespace std;

#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)

#define plln(n) printf("%lld\n",n)

#define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

typedef long long LL;

#define mod 1000000007
#define mx 100011

LL bit[mx][2],bit1[mx],n,k;

void update(LL idx,LL val,LL pos)
{
    while(idx<=100000)
    {
        bit[idx][pos]=(bit[idx][pos]+val)%mod;
        idx+=( idx & -idx );
    }
}

LL query(LL idx,LL pos)
{
    LL sum=0;
    while(idx>0)
    {
        sum=(sum+bit[idx][pos])%mod;
        idx-=( idx & -idx );
    }
    return sum;
}

void update1(LL idx,LL val)
{
    while(idx<=100000)
    {
        bit1[idx]=(bit1[idx]+val)%mod;
        idx+=( idx & -idx );
    }
}

LL query1(LL idx)
{
    LL sum=0;
    while(idx>0)
    {
        sum=(sum+bit1[idx])%mod;
        idx-=( idx & -idx );
    }
    return sum;
}


int main()
{
    LL t,i,j,ans=0;
    sll(n);
    LL a[n+5];
    memset(bit,0,sizeof(bit));
    memset(bit1,0,sizeof(bit1));
    rep1(i,n) sll(a[i]);
    LL first=0,second=0;
    rep1(i,n)
    {
        first=query(a[i]-1,1);
        second=query(100000,0)-query(a[i],0);
        first=first%mod;
        second=(second+mod)%mod;
        first+=query1(a[i]-1);
        second+=query1(100000)-query1(a[i]);
        first=first%mod;
        second=(second+mod)%mod;
        update1(a[i],1);
        update(a[i],first,0);
        update(a[i],second,1);
        ans+=first+second;
        ans=ans%mod;
    }
    cout<<ans;
    return 0;
}


