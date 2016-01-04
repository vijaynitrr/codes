#include<bits/stdc++.h>

using namespace std;

#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)

#define plln(n) printf("%lld\n",n)

#define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

typedef long long LL;

#define MOD 1000000007
#define mx 1<<17

LL n;
LL tree[1<<17],pos[1<<17];

void update(LL idx,LL val)
{
    while(idx<mx)
    {
        tree[idx]+=val;
        idx+=( idx & -idx );
    }
}

LL read(LL idx)
{
    LL sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=( idx & -idx );
    }
    return sum;
}

LL bsearch(LL val)
{
    if ( read( n ) < val ) return n+1;
    int lo, hi, mid, msum, lsum;
    lo = 0; hi = mx;
    lsum = 0;
    while ( lo+1 < hi )
    {
        mid = (lo+hi)/2;
        msum = lsum + tree[mid];
        if ( msum >= val )
            hi = mid;
        else
        {
            lo = mid;
            lsum = msum;
        }
    }
    return hi;
}

void op1(LL val)
{
    LL s=bsearch(read(pos[val]));
    update(s,1);
    if(s<=n) update(s+1,-1);
}

void op2(LL val)
{
    LL i;
    //rep1(i,n)
      //  cout<<tree[i]<<" ";
    //cout<<endl;
    LL s=bsearch(val);
    //cout<<"idx="<<s<<endl;
    plln(n-s+1);
}

void op3(LL val)
{
    LL s=bsearch(val);
    update(s,-1);
}

int main()
{
    LL t,i,j,q,ans,x,y;
    s2ll(n,q);
    memset(tree,0,sizeof(tree));
    vector< pair<LL,LL> > v;
    v.push_back(make_pair(0,0));
    rep1(i,n){
        sll(x);
        v.push_back(make_pair(x,i));
    }
    sort(v.begin()+1,v.end()+1);
    //rep1(i,v.size())
    //    cout<<v[i].first<<" ";
    //cout<<endl;
    rep1(i,n)
    {
        update(i,v[i].first-v[i-1].first);
        pos[v[i].second]=i;
    }
    while(q--)
    {
        s2ll(x,y);
        if(x==1) op1(y);
        else if(x==2) op2(y);
        else op3(y);
    }
    return 0;
}
