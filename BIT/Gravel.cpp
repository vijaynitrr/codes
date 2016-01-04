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
#define mx 1000600

LL cnt[mx],a[mx],b[mx],M[mx];
int n;

void update(LL idx,LL val)
{
    while( idx<=n )
    {
        cnt[idx]+=val;
        idx+=( idx & -idx );
    }
}

LL query(LL idx)
{
    LL sum=0;
    while(idx>0)
    {
        sum+=cnt[idx];
        idx-=( idx & -idx );
    }
    return sum;
}

#define gc getchar_unlocked
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

int main()
{
    int t,i,j,L,m,x,c,R,k,ans;
    char ch;
    n=read_int();
    m=read_int();
    c=read_int();
    memset(cnt,0,sizeof(cnt));
    update(1,c);
    while(m--)
    {
        cin>>ch;
        if(ch=='Q'){
            x=read_int();
            plln(query(x));
        }
        else{
            L=read_int();
            R=read_int();
            x=read_int();
            update(L,x);
            update(R+1,-x);
        }
    }
    return 0;
}

