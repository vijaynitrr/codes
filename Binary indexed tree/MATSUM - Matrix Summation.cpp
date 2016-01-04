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
#define mx 1030

LL bit[1040][1040],mat[1050][1050],a[mx],b[mx],M[mx],n,k;

void update(LL idxx,LL idyy,LL val)
{
    LL y1=idyy;
    while(idxx<=n)
    {
        idyy=y1;
        while(idyy<=n)
        {
            bit[idxx][idyy]+=val;
            idyy+=( idyy & -idyy );
        }
        idxx+=( idxx & -idxx );
    }
}

LL query(LL idxx,LL idyy)
{
    LL sum=0,y1=idyy;
    while(idxx>0)
    {
        idyy=y1;
        while(idyy>0)
        {
            sum+=bit[idxx][idyy];
            idyy-=( idyy & -idyy );
        }
        idxx-=( idxx & -idxx );
    }
    return sum;
}


int main()
{
    LL t,i,j,ans,L1,R1,L2,R2,val;
    sll(t);
    while(t--){
        char str[10];
        sll(n);
        memset(bit,0,sizeof(bit));
        memset(mat,0,sizeof(mat));
        while(1){
            scanf("%s",str);
            if(str[1]=='E'){
                s3ll(L1,R1,val);
                L1++;R1++;
                update(L1,R1,val-mat[L1][R1]);
                mat[L1][R1]=val;
                /*rep1(i,n){
                    rep1(j,n){
                        cout<<bit[i][j]<<" ";
                    }
                    cout<<endl;
                }*/
            }else if(str[1]=='U'){
                s2ll(L1,R1);
                s2ll(L2,R2);
                L1++;R1++;L2++;R2++;
                //cout<<query(L2,R2)<<endl;
                //cout<<query(L1-1,R1-1)<<endl;
                plln(query(L2,R2)+query(L1-1,R1-1)-query(L2,R1-1)-query(L1-1,R2));
            }
            else {
                break;
            }
        }
    }
    return 0;
}

