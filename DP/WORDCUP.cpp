//
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
    LL t,x,sum,n,i,j,ans;
    sll(t);
    while(t--)
    {
        sll(n);
        sum=0;
        vector< pair<LL, pair<LL,LL> > > v;
        rep1(i,n){
            rep1(j,n){
                sll(x);
                v.push_back( make_pair(x,make_pair(i,j)) );
            }
        }
        sort(v.begin(),v.end());
        //cout<<v[0].second.first<<" "<<v[0].second.second<<endl;
        rep(i,v.size()-1){
            sum+=abs(v[i+1].second.first-v[i].second.first)+abs(v[i+1].second.second-v[i].second.second);
        }
        plln(sum);
    }
    return 0;
}
