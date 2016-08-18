#include<bits/stdc++.h>
//#include<cstring>
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
#define mem(arr,n) memset(arr,n,sizeof(arr))
const int INF=0x7f7f7f7f;
typedef long long ll;

//GlobalVar
ll s_cnt;
int N;
int arr[500005];
int mark[500005];
int ta;
int imain(void){
	ta=0;
	int nowMerge=-1;
	int nowFlag=0; 
	rep(N){
		static char CMD[10];
		scanf("%s",CMD);
		if(CMD[0]=='p'){
			char c;
			scanf(" %c",&c);
			if(CMD[1]=='u'){//push
				int num;
				scanf("%d",&num);
				if(c=='A'){
					arr[ta]=num;
					mark[ta]=1;
					ta++;	
				}
				if(c=='B'){
					arr[ta]=num;
					mark[ta]=2;
					ta++;
				}
			}
			else{//pop
				if(c=='A'){
					int i;
					for(i=ta-1;i>=nowMerge+1;i--)
						if(mark[i]==1)
							break;
					if(i==nowMerge){
						for(;i>=0;i--)
							if(mark[i]!=0)
								break;
					}
					printf("%d\n",arr[i]);
					mark[i]=0;
				}
				if(c=='B'){
					int i;
					for(i=ta-1;i>=nowMerge+1;i--)
						if(mark[i]==2)
							break;
					if(i==nowMerge){
						for(;i>=0;i--)
							if(mark[i]!=0)
								break;
					}
					printf("%d\n",arr[i]);
					mark[i]=0;
				}
			}
		}
		else{//merge
			char c1,c2;
			scanf(" %c %c",&c1,&c2);
			int NewMark;
			if(c1=='A'){
				NewMark=1;
			}
			if(c1=='B'){
				NewMark=2;
			}
			/*for(int i=0;i<ta;i++)
				if(mark[i]!=0)	mark[i]=NewMark;*/
			nowMerge=ta-1;
			nowFlag=NewMark;
		}
	}
	return 0;
}
int main(void)
{
	int cntt=0;
	while(scanf("%d",&N),N!=0){
		cntt++;
		printf("Case #%d:\n",cntt);
		imain();
	}
}
