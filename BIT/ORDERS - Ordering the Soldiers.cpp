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
#define mx 1000005

LL bit[mx],n,k,s[mx];

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
    LL t,i,j,k,b,e,x,ans;
    rep1(i,mx) s[i]=i;
    sll(t);
    while(t--)
    {
        sll(n);
        memset(bit,0,sizeof(bit));
        LL res[n+6],a[n+6];
        rep1(i,n){ sll(a[i]); update(i,1);}
        for(i=n;i>0;i--)
        {
            LL chk=i-a[i];
            b=1,e=n;
            while(b<=e)
            {
                LL mid=(b+e)>>1;
                if(query(mid)<chk) b=mid+1;
                else e=mid-1;
            }
            res[i]=b;
            //cout<<res[i]<<" ";
            update(res[i],-1);
        }
        //cout<<endl;
        rep1(i,n) cout<<s[res[i]]<<" ";
        cout<<endl;
    }
    return 0;
}

