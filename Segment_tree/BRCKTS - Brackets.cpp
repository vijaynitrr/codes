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
#define mx 999999

LL ans[mx],o[mx],c[mx];

string str;

void build(LL node,LL l,LL r)
{
	LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(l==r) {
        if(str[l]=='(') o[node]=1;
        else c[node]=1;
        return;
    }
    build(lnode,l,mid);
    build(rnode,mid+1,r);
    LL temp=min(o[lnode],c[rnode]);
    ans[node]=ans[lnode]+ans[rnode]+temp;
    o[node]=o[lnode]+o[rnode]-temp;
    c[node]=c[lnode]+c[rnode]-temp;
}

void update(LL node,LL l,LL r,LL idx)
{
    LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(l==r){
        if(str[l]=='('){ str[l]=')'; o[node]=0; c[node]=1; }
        else { str[l]='('; o[node]=1; c[node]=0; }
        return;
    }
    if( idx<=mid )
    {
        update(lnode,l,mid,idx);
    }
    else{
        update(rnode,mid+1,r,idx);
    }
    LL temp=min(o[lnode],c[rnode]);
    ans[node]=ans[lnode]+ans[rnode]+temp;
    o[node]=o[lnode]+o[rnode]-temp;
    c[node]=c[lnode]+c[rnode]-temp;
}


int main()
{
    LL t,n,i,q,x,j;
    t=10;
    rep1(i,t)
    {
        memset(ans,0,sizeof(ans));
        memset(o,0,sizeof(o));
        memset(c,0,sizeof(c));
        cout<<"Test "<<i<<":"<<endl;
        sll(n);
        cin>>str;
        build(1,0,n-1);
        sll(q);
        while(q--)
        {
            sll(x);
            if(x==0){
                if((ans[1]*2)==n) cout<<"YES\n";
                else cout<<"NO\n";
            }
            else{
                x--;
                update(1,0,n-1,x);
            }
        }
    }
    return 0;
}
