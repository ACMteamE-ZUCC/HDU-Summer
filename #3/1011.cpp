#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
const int MAX=100005;
bool app[MAX<<3];
int x[MAX],y[MAX];
inline int dist(int a,int b){
	return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
int imain(void)
{
	memset(app,false,sizeof(app));
	int n,m;
	cin>>n>>m;
	rep(n){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int dst=dist(i,j);
			if(app[dst]==true){
				return 1;
			}
			else{
				app[dst]=true;
			}
		}
	}
	return 0;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int ans=imain();
		if(ans) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}
