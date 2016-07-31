#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
//GlobalVar

//EndGlobalVar
int main(void)
{
	//ios_base::sync_with_stdio(false);
	int n;
	while(cin>>n){
		double ans=0;
		if(n==1){
			cin>>n;
			cout<<n<<'\n';
			continue;
		}
		rep(n){
			int k;
			cin>>k;
			if(i==1||i==n){
				ans+=k/2.0;
				continue;
			}
			else{
				ans+=k/3.0;
			}
		}
		printf("%.6f\n",ans);
	}
}
