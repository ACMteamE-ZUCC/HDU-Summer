#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
struct STI{
	int* data;
	int size;
	inline int operator [] (int n){return data[n];} 
};
//GlobalVar
const int MAX_N=1005;
const int P=1000000007;
int N,M;
int A[MAX_N];
int B[MAX_N];
int find(STI& a,STI& s);
//EndGlobalVar
STI a,b;
int imain(void)
{
	rep(N) cin>>A[i-1];
	rep(M) cin>>B[i-1];
	a.data=A;a.size=N;
	b.data=B;b.size=M;
	int ans=0;
	for(int i=0;i<M;i++){
		ans=(ans+find(a,b))%P;
		b.data++;
		b.size--;
	}
	return ans;
}
int main(void)
{
	while(scanf("%d%d",&N,&M)!=EOF){
		cout<<imain()<<'\n';
	}
}
int f[MAX_N];
void getfill(STI& s)
{  
    memset(f,0,sizeof(f));  //根据其前一个字母得到  
    for(int i=1;i<s.size;i++)  
    {  
        int j=f[i];  
        while(j && s[i]!=s[j])  
            j=f[j];  
        f[i+1]=(s[i]==s[j])?j+1:0;  
    }  
}
int find(STI& a,STI& s)  
{  
    int ans=0;  
    getfill(s);int j=0;  
    for(int i=0;i<a.size;i++)  
    {  
        while(j && a[i]!=s[j]){
            j=f[j];  
        	if(j!=0)ans++;
        }  
        if(a[i]==s[j]){
            j++;  
        	ans++;
        }  
        /*if(j==s.size){  

        }  */
    }  
    return ans;  
}
