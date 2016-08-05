#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
typedef long long ll;
//GlobalVar
int n,m;
int ve[10000000];
//EndGlobalVar
ll work(int pos,int sum)
{
	ll ans=0;
	if(pos==m+1){
		
	}
	for(int i=0;i<10;i++){
		if(sum+i>n||i<ve[pos]) break;
		ve[pos]=i;
		ans+=work(pos+1,sum+i);
	}
	return ans;
}
int main(void)
{
	while(cin>>n>>m){
		memset(ve,0,sizeof(ve));
		cout<<work(1,0)<<'\n';	
	}
}