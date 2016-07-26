#include<bits/stdc++.h>
using namespace std;
int n;
int c[1010];
double expt0[1005];
double expt1[1005];
int imain(void)
{
	expt0[n]=0;
	expt1[n]=c[n];
	for(int i=n-1;i>=1;i--){
		expt0[i]=(expt0[i+1]+expt1[i+1])/2;
		expt1[i]=(expt0[i+1]+c[i]);
	}
	cout<<(expt0[1]+expt1[1])/2<<'\n';
	return 0;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	while(cin>>n){
		for(int i=1;i<=n;i++)
			cin>>c[i];
		imain();
	}
}
