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
#define mx 10000001

LL n;

struct point
{
  LL type;
  LL x;
  LL y;
  LL val;
  LL chk;
};

LL bit[mx];
struct point q[mx];

bool cmp(point const& lhs,point const& rhs)
{
  if (lhs.y != rhs.y)
      return lhs.y < rhs.y;
  if (lhs.x != rhs.x)
      return lhs.x < rhs.x;
  else{
      if((lhs.type == 1 && rhs.type == 2) || (lhs.type == 2 && rhs.type == 1) ){
          return lhs.type == 1 ? false : true;
      }
      if((lhs.type == 1 && rhs.type == 3) || (lhs.type == 3 && rhs.type == 1) ){
          return lhs.type == 1 ? true : false;
      }
  }
}

void update(LL idx,LL val)
{
  while(idx<=10000001)
  {
      bit[idx]=(bit[idx]+val);
      idx+=( idx & -idx );
  }
}

LL read(LL idx)
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
  LL t,i,j,a,b,c,d,data,r,cnt,ans;
  sll(t);
  while(t--)
  {
      cnt=0;
      memset(bit,0,sizeof(bit));
      sll(n);
      rep(i,n){
          s3ll(a,b,data);
          q[cnt].x=a+1;
          q[cnt].y=b+1;
          q[cnt].type=1;
          q[cnt].val=data;
          cnt++;
      }
      sll(r);
      rep(i,r){
          s2ll(a,b);
          s2ll(c,d);
          q[cnt].x=a+1;
          q[cnt].y=b+1;
          q[cnt].type=2;
          q[cnt].val=i;
          q[cnt].chk=c+1;
          cnt++;
          q[cnt].x=c+1;
          q[cnt].y=d+1;
          q[cnt].type=3;
          q[cnt].val=i;
          q[cnt].chk=a+1;
          cnt++;
      }
      sort(q,q+cnt,cmp);
      //qsort(q,cnt,sizeof(point),cmp);
      /*for(int i = 0 ; i < 2 * r + n ; i++){
          cout<<q[i].type<<" "<<q[i].x<<" "<<q[i].y<<" "<<q[i].val<<endl;
      }*/
      LL output[r+5];
      memset(output,0,sizeof(output));
      rep(i,cnt){
          if(q[i].type==1){
              update(q[i].x,q[i].val);
          }else if(q[i].type==2){
              output[q[i].val]-=read(q[i].chk)-read(q[i].x-1);
          } else{
              output[q[i].val]+=read(q[i].x)-read(q[i].chk-1);
          }
      }
      rep(i,r){
          plln(output[i]);
      }
  }
  return 0;
}
