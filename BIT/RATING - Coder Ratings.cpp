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
#define mx 300005

vector< pair<LL,pair<LL,LL> > > v;

bool cmp(pair<LL,pair<LL,LL> > a,pair<LL,pair<LL,LL> > b)
{
    if(a.second.first==b.second.first) return a.second.second<b.second.second;
    return a.second.first<b.second.first;
}

LL bit[mx],n,k;

void update(LL idx,LL val)
{
    while(idx<=mx)
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
    LL t,n,i,j,k=0,x;
    sll(n);
    LL a,h,ans[n+5];
    memset(bit,0,sizeof(bit));
    rep(i,n){
        s2ll(a,h);
        v.push_back(make_pair(i,make_pair(a,h)));
    }
    sort(v.begin(),v.end(),cmp);
    /*rep(i,v.size()){
        cout<<v[i].second.first<<" "<<v[i].second.second<<endl;
    }*/
    k=1;
    LL prev=1;
    ans[v[0].first]=0;
    update(v[0].second.second,1);
    rep1(i,v.size()-1){
        if( (i>0)&&(v[i].second.first!=v[i-1].second.first)||(v[i].second.second!=v[i-1].second.second)){
            ans[v[i].first]=query(v[i].second.second);
        }else{
            ans[v[i].first]=query(v[i].second.second)-1;
        }
         update(v[i].second.second,1);
    }
    rep(i,n) cout<<ans[i]<<endl;
    return 0;
}
