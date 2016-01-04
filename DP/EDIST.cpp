//http://www.spoj.com/problems/EDIST/

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

LL lcs[2005][2005];

int main()
{
    LL t,n,i,j,ans;
    string x,y;
    sll(t);
    while(t--)
    {
        ans=0;
        cin>>x;
        cin>>y;
        LL m=x.length();
        LL n=y.length();
        for(i=0;i<=m;i++)
        {
            for(j=0;j<=n;j++)
            {
                if( i==0 || j==0 ) lcs[i][j]=0;
                else if(x[i-1]==y[j-1]) { lcs[i][j]=lcs[i-1][j-1]+1; ans=max(ans,lcs[i][j]);}
                else lcs[i][j]=0;
            }
        }
        ans=max(m,n)-ans;
        plln(ans);
    }
    return 0;
}
