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

vector<int> ans;

struct trie
{
    bool sorted;
    vector<int> idx;
    struct trie *child[26];
};
set<string> st;
string str[20005];
void initialize(struct trie *node)
{
    node->sorted=false;
    for(int i=0;i<26;i++)
        node->child[i]=NULL;
}

inline void addWord(struct trie *node,string sr,int pos,int cnt)
{
    if(cnt==sr.length()){
        //cout<<"aata";
        return;
    }
    else
    {
        //cout<<sizeof(struct trie)<<endl;
        node->idx.push_back(pos);
        char ch=sr[cnt];
        if(node->child[ch-'a']==NULL)
        {
            node->child[ch-'a']=new trie;
            initialize(node->child[ch-'a']);
        }
        addWord(node->child[ch-'a'],sr,pos,cnt+1);
    }
}

inline bool cmp(const int a,const int b)
{
    return str[a]<str[b];
}

inline void solve(struct trie *root,string s)
{
    int i;
    struct trie *root1=root;
    rep(i,s.length()){
        root1=root1->child[s[i]-'a'];
        if(root1==NULL) return;
    }
    if(root1)
    {
        if(!root1->sorted){
            sort(root1->idx.begin(),root1->idx.end(),cmp);
            root1->sorted=true;
        }
        ans=root1->idx;
    }
}

int main()
{
    int i,n,t,m,j,k=0,chk,flag;
    struct trie *root=NULL;
    root=new trie;
    initialize(root);
    string s;
    scanf("%d",&n);
    rep(i,n){
        cin>>s;
        if(st.find(s)==st.end())
        {
            st.insert(s);
            str[k++]=s;
            addWord(root,s,k-1,0);
        }
    }
    scanf("%d",&m);
    rep1(i,m){
        ans.clear();
        printf("Case #%d:\n",i);
        cin>>s;
        solve(root,s);
        if(!ans.size())
            printf("No match.\n");
        else{
            rep(j,ans.size())
                cout<<str[ans[j]]<<endl;
        }
    }
    return 0;
}
