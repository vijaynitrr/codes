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
#define mx 1030

LL bit[1040][1040],mat[1050][1050],a[mx],b[mx],M[mx],n,k;

void update(LL idxx,LL idyy,LL val)
{
    LL y1=idyy;
    while(idxx<=n)
    {
        idyy=y1;
        while(idyy<=n)
        {
            bit[idxx][idyy]+=val;
            idyy+=( idyy & -idyy );
        }
        idxx+=( idxx & -idxx );
    }
}

LL query(LL idxx,LL idyy)
{
    LL sum=0,y1=idyy;
    while(idxx>0)
    {
        idyy=y1;
        while(idyy>0)
        {
            sum+=bit[idxx][idyy];
            idyy-=( idyy & -idyy );
        }
        idxx-=( idxx & -idxx );
    }
    return sum;
}


int main()
{
    LL t,i,j,ans,L1,R1,L2,R2,val;
    sll(t);
    while(t--){
        memset(bit,0,sizeof(bit));
    }
    return 0;
}

