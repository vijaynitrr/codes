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

LL bit[mx],n,k,cnt[mx];

void update(LL idx,LL val)
{
    while(idx<=mx)
    {
        bit[idx]=(bit[idx]+val);
        idx+=( idx & -idx );
    }
}

LL read(LL idx)
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
    LL t,i,j,a,b,ans;
    sll(n);
    memset(bit,0,sizeof(bit));
    memset(cnt,0,sizeof(cnt));
    while(n--)
    {
        s2ll(a,b);
        LL x=read(a);
        LL y=read(b);
        plln(x+y-cnt[a]-cnt[b]);
        cnt[a]=x;
        cnt[b]=y;
        update(a+1,1);
        update(b,-1);
        //for(i=1;i<=8;i++)
          //  cout<<bit[i]<<" ";
        //cout<<endl;
    }
    return 0;
}

