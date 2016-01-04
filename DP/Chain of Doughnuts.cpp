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
#define mx 999999

int main()
{
    LL t,n,i,j,m,ans;
    sll(t);
    while(t--)
    {
        ans=0;
        s2ll(n,m);
        LL a[m+5];
        rep(i,m){
            sll(a[i]);
        }
        sort(a,a+m);
        m--;
        LL k=0,p=m;
        while(m>0)
        {
            p=m;
            m=m-a[k]-1;
            if(m>=0) ans+=a[k];
            else ans+=p;
            k++;
        }
        plln(ans);
    }
    return 0;
}
