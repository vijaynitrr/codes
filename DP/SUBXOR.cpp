//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2683

#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    node * first; node * second;
    node (node * a, node * b){first=a; second=b;}
};
node * root = new node (NULL, NULL);
void insert (node * x, int bits, int pos)
{
    if (pos==-1) return;
    if ((1<<pos)&bits)
    {
        if (x->second==NULL)
        {
            x->second=new node (NULL, NULL);
        }
        insert(x->second, bits, pos-1);
    }
    else
    {
        if (x->first==NULL)
        {
            x->first=new node (NULL, NULL);
        }
        insert(x->first, bits, pos-1);
    }
}
void query (node * t, int a, int pos, int & ans)
{
  if (pos==-1) return;
  if ((1<<pos)&a)
  {
      if (t->first==NULL)
      {
          query (t->second, a, pos-1, ans);
      }
      else
      {
          ans+=pow(2, pos); query (t->first, a, pos-1, ans);
      }
  }
  else
  {
      if (t->second==NULL)
      {
          query(t->first, a, pos-1, ans);
      }
      else
      {
          ans+=pow(2, pos); query(t->second, a, pos-1, ans);
      }
  }
}
main()
{
     int a; scanf("%lld", &a);
     for (int g=0; g<a; g++)
     {
         int curxor=0, anss=0;
         int b; scanf("%lld", &b);vector <int> t; int leng=31;
         for (int y=0;y<b; y++)
         {
             int c; scanf("%lld", &c); curxor^=c;t.push_back(curxor); anss=max(anss, curxor);
         }
         for (int y=0;y<t.size(); y++)
         {
            insert(root, t[y], leng); int ans=0;
            query(root, t[y], leng, ans);
            anss=max(anss, ans);
         }cout << anss <<endl;
         root=new node (NULL, NULL);
     }
     return 0;
}
