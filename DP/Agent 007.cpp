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
    LL t,n,i,j,ones,zeros,ans;
    sll(t);
    while(t--)
    {
        ones=0;
        string str;
        cin>>str;
        sll(n);
        rep(i,str.length()){
            if(str[i]=='1') ones++;
        }
        zeros=str.length()-ones;
        if(((((n+1)/2)%2)==0)) plln(ones);
        else plln(zeros);

    }
    return 0;
}
