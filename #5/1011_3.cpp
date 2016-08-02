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
int SSum(int i,int j);
void add(int row,int col,ll val);
//EndGlobalVar
ll ans=0;
int imain(void)
{
	rep(N) scanf("%d",&a[i]);
	rep(M) scanf("%d",&b[i]);
	ans=0;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			if(b[i]==a[j]){
				int t=SSum(i-1,j-1);
				add(i,j,t+1);
			}
		}
	}
	cout<<SSum(M,N)<<'\n';
	return 0;
}
int t[MAXN][MAXN];
int main(void)
{
	while(scanf("%d%d",&N,&M)!=EOF){
		memset(t,0,sizeof(t));
		imain();
	}	
}
inline int lowbit(int n){
	return n&(-n);
}
void add(int row,int col,ll val)  
{  
    for(int i=row;i<MAXN;i+=lowbit(i))  
    	for(int j=col;j<MAXN;j+=lowbit(j))  {
    		ll temp=t[i][j]+val;
    		temp%=P;
        	t[i][j]=(int)temp;  
    	}
}  
int Sum(int row,int col)  
{  
    ll ans=0;  
    for(int i=row;i>0;i-=lowbit(i))  
    for(int j=col;j>0;ans=(ans+t[i][j])%P,j-=lowbit(j));  
    return (int)ans;
}  
int SSum(int i,int j){
	ll ans=(ll)Sum(i,j)-Sum(0,j)-Sum(i,0)+Sum(0,0);
	ans%=P;
	return (int)ans;
}
