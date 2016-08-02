#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
//GlobalVar
const int MAX_N=100005;
const int INF=0x7f7f7f7f;
int n;
int a[MAX_N];
//EndGlobalVar
int BSearch( int v) //二分求上界  
{  
	int x=0,y=n-1;
    while(x <= y)  
    {  
        int mid = x+(y-x)/2;  
        if(S[mid] <= v) x = mid+1;  
        else y = mid-1;  
    }  
    return x;  
} 
int LIS(){
	static int s[MAX_N];
	static int d[MAX_N];
	memset(s,INF,sizeof(int)*n);
	int ans=0;
	for(int i=0;i<n;i++){
		int pos=lowwer_bound()
	}
}
int imain(void)
{
	cin>>n;
	rep(n) cin>>a[i-1];
	int ans=LIS();

}
int main(void)
{
	int T;
	cin>>T;
	rep(T){
		imain();
	}
}