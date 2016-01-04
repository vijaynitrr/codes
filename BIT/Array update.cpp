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
#define mx 100005

LL bit[mx],n,k;

void update(LL idx,LL val)
{
    while(idx<=n)
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
    LL p,i,q,val,L,R,x;
    sll(p);
    while(p--)
    {
        memset(bit,0,sizeof(bit));
        s2ll(n,k);
        while(k--)
        {
            s3ll(L,R,val);
            update(L,val);
            update(R+1,-val);
        }
        sll(q);
        while(q--)
        {
            sll(R);
            plln(query(R));
        }
    }
    return 0;
}

