#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
//GlobalVar
const int P=110119;
int a[10000][10000];
map<int,int> ma;
//EndGlobalVar
int main(void)
{
	memset(a,0,sizeof(a));
	for(int i=1;i<10000;i++){
		for(int j=1;j<10000;j++){
			if(i==1||j==1)
				a[i][j]=1;
			else
				a[i][j]=a[i-2][j-1]+a[i-1][j-2];
			a[i][j]%=P;
			if(i==j){
				if(ma[a[i][j]]==1){
					cout<<i<<' '<<j;
					return 0;
				}
				ma[a[i][j]]++;
			}
		}
	}
}
