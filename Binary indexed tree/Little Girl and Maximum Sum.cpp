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
#define mx 200005

LL bit[mx],n,k;

LL cnt[mx];
void update(LL idx,LL val)
{
    while(idx<=mx)
    {
        bit[idx]=(bit[idx]+val);
        idx+=( idx & -idx );
    }
}

LL query(LL idx)
{
    LL sum=0;
    while(idx>0)
    {
        sum=(sum+bit[idx]);
        idx-=( idx & -idx );
    }
    return sum;
}


int main()
{
    LL t,i,j,ans=0;
    s2ll(n,k);
    LL a[n+5],ind[n+5];
    rep1(i,n) sll(a[i]);
    sort(a+1,a+n+1);
    memset(bit,0,sizeof(bit));
    LL L,R;
    rep(i,k){
        s2ll(L,R);
        update(L,1);
        update(R+1,-1);
    }
    rep1(i,n){
        ind[i]=query(i);
    }
    sort(ind+1,ind+n+1);
    for(i=n;i>0;i--)
    {
        ans+=(ind[i]*a[i]);
    }
    plln(ans);
    return 0;
}

