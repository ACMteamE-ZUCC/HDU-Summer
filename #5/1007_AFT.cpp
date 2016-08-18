#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
#define mem(ar,n) memset(ar,n,sizeof(ar))
typedef long long ll;
//GlobalVar
int K;
int num[20];
int WS;
//EndGlobalVar
ll dp[20][100000];
int arr_s[50];
int *arr=arr_s+8;
ll dfs(int pos,int* end,int lmt){
	if(pos==0){
		return 1;
	}
	int a=0;
	for(int i=K-2;i>=0;i--){
		a*=10;
		a+=end[i]==-1?0:end[i];
	}
	if(dp[pos][a]!=0&&lmt==0){
		return dp[pos][a];
	}
	ll ans=0;
	int upbound=10;
	if(lmt==1){
		upbound=num[pos];
		for(int i=0;i<K-1;i++){
			if(end[i]==upbound) goto mar;
		}
		if(end[K-2]!=-1||upbound!=0)end[K-1]=upbound;//TODO when upbound is the first number but it equal to 0
		ans+=dfs(pos-1,end+1,1);
		end[K-1]=-1;
	}
	mar:int mark=0;
	for(int i=0;i<upbound;i++){
		int flag=1;
		for(int j=0;j<K-1;j++){
			if(end[j]==i){
				flag=0;
			}
		}
		if(flag==0) continue;
		if(end[K-2]!=-1||i!=0)end[K-1]=i;//TODO 
		ans+=dfs(pos-1,end+1,0);
		end[K-1]=-1;
	}
	if(lmt==0) dp[pos][a]=ans;
	return ans;
}
ll calc(ll n){
	static int table_k=0;
	if(table_k!=K){
		table_k=K;
		mem(dp,0);
	}
	WS=0;
	while(n>0){
		num[++WS]=n%10;
		n/=10;
	}
	mem(arr_s,-1);
	return dfs(WS,arr-(K-2),1);
}
int main(void)
{
	ll L,R;
	while(cin>>L>>R>>K){
		cout<<(calc(R)-calc(L-1))<<'\n';		
	}
	/*K=5;
	cout<<calc(99)<<'\n';
	cout<<calc(100)<<'\n';*/
}
