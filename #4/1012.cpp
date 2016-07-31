#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
   int n,count=1;
   cin>>n;
   int a[100005],b[100005];
   while(n--){
   	int num;
   	cin>>num;
   	for(int i=1;i<=num;i++){
   		cin>>a[i];
   		b[a[i]]=abs(a[i]-i);
	   }
	   cout<<"Case "<<"#"<<count++<<": ";
	   for(int i=1;i<=num;i++){
	   	cout<<b[i]<<" ";
	   	
	   }
	   cout<<endl;
   }	
}
