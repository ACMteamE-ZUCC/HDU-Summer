#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
typedef long long ll;
//GlobalVar
const int maxLen = 100005;
const ll p=1000000007;
char src[maxLen];
char chk[maxLen];
bool head[maxLen];
ll dp[maxLen];
//EndGlobalVar
// int kmp_match(char source[],char checked[]); 
int find(string a,string s);
ll imain(void){
	cin>>src;
    int lth=strlen(src);
	cin>>chk;
    int lths=strlen(chk);
	memset(head,false,sizeof(head));
	find(src,chk);
    bool first=true;
    ll ans=1;
    for(int i=0;i<lth;i++){
        if(head[i]==true){
            if(first){
                first=false;
                ans+=1;
            }
            else{
                // dp[i]=(dp[i-lths]*2)%p;
                ans=(ans+dp[i-lths])%p;
            }
        }
        dp[i]=ans;
    }
	return ans;
}
int main(void)
{
	int T;
	scanf("%d",&T);
	rep(T){
		ll ans=imain();
        printf("Case #%d: ",i);
        cout<<ans<<'\n';
	}
}
int f[ 15000];  
void getfill(string s)  
{  
    memset(f,0,sizeof(f));  //根据其前一个字母得到  
    for(int i=1;i<s.size();i++)  
    {  
        int j=f[i];  
        while(j && s[i]!=s[j])  
            j=f[j];  
        f[i+1]=(s[i]==s[j])?j+1:0;  
    }  
}  
int find(string a,string s)  
{  
    int ans=0;  
    getfill(s);int j=0;  
    for(int i=0;i<a.size();i++)  
    {  
        while(j && a[i]!=s[j])  
            j=f[j];  
        if(a[i]==s[j])  
            j++;  
        if(j==s.size()){  
            head[i]=true;
            ans++;  
        }  
    }  
    return ans;  
}
/*
// 最大字符串长度
int num;
// 前一个匹配位置,多次匹配注意要重新初始化
// 注：preMatch[i]表示0~preMatch[i-1]能和?~i匹配
int preMatch[maxLen];

int kmp_match(char source[],char checked[]) {
    int i = 0, j = 0;
    memset(preMatch, 0, sizeof(preMatch));

    if(!checked[i]) // 被匹配串为空串，直接返回 0
        return 0;

    ++ i;
    while(checked[i]) {
        for(j = preMatch[i - 1]; checked[i] != checked[j] && j; j = preMatch[j - 1]);
        preMatch[i] = (checked[i] == checked[j])? j + 1 : 0 ;
        ++ i;
    }
    //计算匹配子串个数(子串间无重叠)(与以下一起二选一)
    num = 0;//计数变量
    for(i = j = 0; source[i]; ++ i) {
        if(checked[j] == source[i]){
            j++;
        }
        else if(j){
            i++;
            j = preMatch[j - 1];
        }
        if(!checked[j]){
        	num++;
        	head[i]=true;
            j = preMatch[j - 1];//如果要子串间重叠 则此句中j = 0 改成 j = preMatch[j - 1]
        }
    }
    return num;
}
*/
