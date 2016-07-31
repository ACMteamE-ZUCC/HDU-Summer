#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
//GlobalVar

//EndGlobalVar
map<string,int> m;
int main(void)
{
	for(int i=1;i<=70;i++){
		char s1[10000];
		gets(s1);
		char *ss=s1+8;
		string s(ss);
		m[s]=m[s]+1;
	}
	for(auto it=m.begin();it!=m.end();it++){
		cout<<it->first<<','<<it->second<<'\n';
	}
}
