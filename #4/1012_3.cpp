#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
//GlobalVar
const int MAX=100005;

//EndGlobalVar

//BIT-Template Begin
typedef int BIT_c;
const int BIT_MAX=MAX;
BIT_c BIT[BIT_MAX];
inline int lowbit(const int &n){
	return n&(-n);
}
inline int op_upper(const int &n){
	return n+lowbit(n);
}
inline int op_lower(const int &n){
	return n-lowbit(n);
}
int bit_add(int ith,BIT_c dlt){
	while(ith<=BIT_MAX){
		BIT[ith]+=dlt;
		ith=op_upper(ith);
	}
	return 0;
}
BIT_c bit_sum(int ith){
	BIT_c ans=0;
	while(ith>0){
		ans+=BIT[ith];
		ith=op_lower(ith);
	}
	return ans;
}
int bit_init(){
	memset(BIT,0,sizeof(BIT));
	return 0;
}
//BIT-Template End

//imainGlb Begin
int a[MAX];
int b[MAX];	
int mm[MAX];
//imainGlb End
int imain(void)
{
	int N;
	cin>>N;
	rep(N){
		cin>>a[i];
		mm[a[i]]=i;
	} 
	bit_init();
	for(int i=N;i>=1;i--){
		b[a[i]]=bit_sum(a[i]);
		bit_add(a[i],1);
	}
	for (int i = 1; i <=N; i++) {
			int ans;
			if (mm[i] >= i) {
				ans=mm[i]+b[i]-i;
			}
			else if (mm[i] < i) {
				ans=b[i];
			}
			cout<<ans;
			if(i!=N) cout<<' ';
	}
	cout<<'\n';
	return 0;
}
int main(void)
{
	int T;
	cin>>T;
	rep(T){
		printf("Case #%d: ",i);
		imain();
		
	}
}
