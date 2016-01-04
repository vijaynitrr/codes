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

struct trie
{
    int child[27];
};
trie node[200005];
string ans;
int qlen;
int root;
int cnt;

void addWord(string str)
{
    int current=root,i;
    rep(i,str.length()){
        int ch=str[i]-'a';
        if(node[current].child[ch]==-1)
        {
            cnt++;
            node[current].child[ch]=cnt;
            memset(node[cnt].child,-1,sizeof(int)*27);
        }
        current=node[current].child[ch];
    }
    //cout<<current<<" ";
    node[current].child[26]=0;
}

int flag;

int wordsearch(string str)
{
    int curr=root,i;
    rep(i,str.length())
    {
        int ch=str[i]-'a';
        if(node[curr].child[ch]==-1) return -1;
        curr=node[curr].child[ch];
    }
    return curr;
}

void print(int curr,int len,string s,string str)
{
    if((node[curr].child[26]==0)&&(len>s.length()))
    {
        cout<<str<<endl;
        flag=1;
    }
    for(int i=0;i<26;i++){
        string str1=str;
        if(node[curr].child[i]!=-1){
            str+='a'+i;
            print(node[curr].child[i],len+1,s,str);
        }
        str=str1;
    }
}

int main()
{
    int i,n,t,m,j,k=0,chk;
    root=0,cnt=0;
    memset(node[root].child,-1,sizeof(int)*27);
    string s;
    scanf("%d",&n);
    rep(i,n){
        cin>>s;
        addWord(s);
    }
    //cout<<endl;
    scanf("%d",&m);
    rep1(i,m){
        printf("Case #%d:\n",i);
        cin>>s;
        ans="";
        int check = wordsearch(s);
        if(check==-1)
            printf("No match.\n");
        else{
            //cout<<"aaya"<<endl;
            ans+=s;
            flag=0;
            print(check,s.length(),s,ans);
            if(!flag) printf("No match.\n");
        }
    }
    return 0;
}

