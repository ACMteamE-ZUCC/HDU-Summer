#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
typedef long long ll;
//GlobalVar
const int MAXN=50005;
int n;
int a[MAXN];
//EndGlobalVar
int main(void)
{
	while(scanf("%d",&n)!=EOF){
		unordered_map<int,int> ma;
		unordered_map<int,int> ma2;
		ll sumr=0;
		ll cnt=0;
		ll ans=0;
		rep(n) scanf("%d",&a[i-1]);
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]>a[j]){
					sumr++;
					ma[a[i]]++;
					ma[a[j]]++;
				}
				else{
					cnt++;
					ma2[a[i]]++;
					ma2[a[j]]++;
				}
			}
		}
		ans=cnt*sumr;
		for(auto it=ma2.begin();it!=ma2.end();it++){
			ans-=ma[it->first]*(it->second);
		}
		cout<<ans<<'\n';
	}
}
