#include<bits/stdc++.h>

using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)

#define plln(n) printf("%lld\n",n)

#define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

typedef long long LL;

#define MOD 1000000007
#define mx 100000004

LL two[mx+4],three[mx+4];

int main()
{
    LL t,n,i,j,ans;
    three[0]=1;
    two[0]=1;
    rep1(i,mx){
        three[i]=(three[i-1]*3)%MOD;
        two[i]=(two[i-1]*2)%MOD;
    }
    sll(t);
    while(t--)
    {
        sll(n);
        ans=(3*(three[n-1]-two[n]+1))%MOD;
        plln(ans);
    }
    return 0;
}
