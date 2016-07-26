#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
char s[1000];
ll n;
int imain(void)
{
	if(strlen(s)>=18){
		 cout<<"TAT"<<'\n';
		 return 0;
	}
	else{
		sscanf(s,"%lld",&n);
	}
	int cnt=0;
	while(n!=1){
		n=(ll)sqrt(n);
		cnt++;
		if(cnt>5){
			cout<<"TAT"<<'\n';
			return 0;
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
int main(void)
{
	while(cin>>s){
		imain();
	}
}
