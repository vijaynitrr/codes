#include<bits/stdc++.h>

using namespace std;

#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)

#define plln(n) printf("%lld\n",n)

#define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

#define countSetBits(n) __builtin_popcountll(n)

typedef long long LL;

#define mod 1000000007
#define mx 999999

LL ans[3005];

int main()
{
    LL t,n,i,j,k,x,sze=0;
    list<LL> v;
    for(i=2;i<=40000;i++) v.push_back(i);
    list<LL>::iterator it,it2;
    while( !v.empty() && sze<3000 ){
        ans[sze++]=v.front();
        k=v.front();
        LL p=k;
        for(it=v.begin();it!=v.end();p++){
            it2=it;it2++;
            if(p%k==0) v.erase(it);
            it=it2;
        }
    }
    while(1){
        sll(n);
        if(n==0) break;
        plln(ans[n-1]);
    }
    return 0;
}
