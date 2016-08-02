#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
typedef long long ll;
//GlobalVar
const int MAXN=1005;
const int P=1000000007;
int N,M;
int a[MAXN];
int b[MAXN];
int dp[MAXN][MAXN];
//EndGlobalVar
ll ans=0;
int imain(void)
{
	rep(N) scanf("%d",&a[i]);
	rep(M) scanf("%d",&b[i]);
	memset(dp,0,sizeof(dp));
	ans=0;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			if(b[i]==a[j]){
				dp[i][j]=(int)( ( (ll)dp[i-1][j-1]+1)%P) ;
				ans+=dp[i][j];
				ans%=P;
			}
			else{
				//dp[i][j]=(int)( ( (ll)dp[i-1][j-1])%P) ;
				dp[i][j]=(int)( ( (ll)dp[i-1][j-1]+dp[i][j-1])%P );
			}
		}
	}
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++)
			cout<<dp[i][j]<<' ';
		cout<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
int main(void)
{
	while(scanf("%d%d",&N,&M)!=EOF){
		imain();
	}	
}
