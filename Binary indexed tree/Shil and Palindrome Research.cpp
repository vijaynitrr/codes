#include<bits/stdc++.h>

using namespace std;

#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)

#define plln(n) printf("%lld\n",n)

#define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

typedef long long LL;

#define mod 5000000
#define mx 100005

LL bit[mx][28],n,k;

void update(LL idx,LL pos,LL val)
{
    while(idx<=mx)
    {
        bit[idx][pos]=(bit[idx][pos]+val);
        idx+=( idx & -idx );
    }
}

LL query(LL idx,LL pos)
{
    LL sum=0;
    while(idx>0)
    {
        sum=(sum+bit[idx][pos]);
        idx-=( idx & -idx );
    }
    return sum;
}


int main()
{
    LL t,i,j,sum,L,R,x,ind;
    char ch;
    s2ll(n,k);
    string str;
    cin>>str;
    rep(i,str.length()){
        update(i+1,str[i]-'a',1);
    }
    while(k--){
        sll(x);
        if(x==1){
            sll(i);
            cin>>ch;
            update(i,str[i-1]-'a',-1);
            str[i-1]=ch;
            update(i,str[i-1]-'a',1);
        }else{
            LL odd=0;
            s2ll(L,R);
            rep(i,26){
                sum=query(R,i)-query(L-1,i);
                if(sum%2!=0) odd++;
            }
            if(odd<=1) cout<<"yes\n";
            else cout<<"no\n";
        }
    }
    return 0;
}

