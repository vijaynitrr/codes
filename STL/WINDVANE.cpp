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

#define mod 4
#define mx 999999

int main()
{
    LL t,n,i,q,j,k,x,m,ans,y,val,x1,y1,x2,y2;
    s2ll(m,n);
    char ch;
    map<char,LL> mp;
    mp['N']=0;
    mp['E']=1;
    mp['S']=2;
    mp['W']=3;
    map<LL,char> m1;
    m1[0]='N';
    m1[1]='E';
    m1[2]='S';
    m1[3]='W';
    LL a[m+5][n+5];
    rep1(i,m){
        rep1(j,n){
            scanf(" %c", &ch);
            a[i][j]=mp[ch];
        }
    }
    sll(q);
    LL flag=0;
    while(q--)
    {
        scanf(" %c", &ch);
        if(ch=='C'){
            s2ll(x1,y1);
            s2ll(x2,y2);
            sll(val);
            for(i=x1;i<=x2;i++){
                for(j=y1;j<=y2;j++){
                    if(val==0) a[i][j]++;
                    else a[i][j]--;
                }
            }
        }else{
            s2ll(x,y);
            //cout<<a[x][y]<<endl;
            if(flag==0) { cout<<m1[(a[x][y]+mod)%mod]<<endl; flag=1;}
            else{
                cout<<endl<<m1[(a[x][y]+mod)%mod]<<endl;
            }
        }
    }
    return 0;
}
