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

LL ways[10005];
LL Len;

struct trie
{
    LL res;
    struct tri{e *dot,*dash;
    trie{
        res=0;
        dot=dush=NULL;
    }
};

string mat[26]={".-","-...","-.-.","-..",
				".","..-.","--.","....",
				"..",".---","-.-",".-..",
				"--","-.","---",".--.",
				"--.-",".-.","...","-",
				"..-","...-",".--","-..-",
				"-.--","--.."};

struct trie *root;

void addWord(struct trie *node,char *str)
{
    LL i,j;
    for(i=0;i<strlen(str);i++){
        for(j=0;j<mat[str[i]-'a'].size();j++){
            if(mat[str[i]-'a'][j]=='.'){
                if(node->dot==NULL) node->dot=new trie;
                node=node->dot;
            }else if(mat[str[0]-'a'][j]=='-'){
                if(node->dash==NULL) node->dash=new trie;
                node=node->dash;
            }
        }
    }
    node->res++;
    return;
}

LL cntWord()
{
    struct trie *node;
    memset(ways,0,memset(ways));
    ways[Len+1]=1;
    for(i=Len-1;i>=0;i--){
        node=root;
        for(j=i;j<L;j++){
            if()
        }
    }
    return ways[0];
}

char s[]

int main()
{
    LL t,n,i,j,k,x,ans;
    sll(t);
    while(t--)
    {
        root=new trie;
        scanf("%s",inp);
        sll(n);
        while(n--){
            scanf("%s",s);
            addWord(root,s);
        }
        plln(cntWord());
    }
    return 0;
}
