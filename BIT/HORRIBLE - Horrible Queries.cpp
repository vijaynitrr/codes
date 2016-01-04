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

LL bit1[mx],bit2[mx],n,k;

void update(LL bit[],LL idx,LL val)
{
    while(idx<=n)
    {
        bit[idx]=bit[idx]+val;
        idx+=( idx & -idx );
    }
}

LL query(LL bit[],LL idx)
{
    LL sum=0;
    while(idx>0)
    {
        sum=(sum+bit[idx]);
        idx-=( idx & -idx );
    }
    return sum;
}

LL query(LL idx)
{
    return (query(bit1,idx)*idx)-(query(bit2,idx));
}
int main()
{
    LL t,i,j,L,R,val,x,k,q,ans;
    sll(t);
    while(t--)
    {
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));
        s2ll(n,k);
        while(k--)
        {
            sll(x);
            if(x==0){
                s3ll(L,R,val);
                update(bit1,L,val);
                update(bit1,R+1,-val);
                update(bit2,L,val*(L-1));
                update(bit2,R+1,-val*R);
            }else{
                s2ll(L,R);
                plln(query(R)-query(L-1));
            }
        }
    }
    return 0;
}

