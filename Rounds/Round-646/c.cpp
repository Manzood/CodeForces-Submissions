#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n, x;
		scanf("%d%d",&n,&x);
		int deg=0;
		for (int i=0;i<n-1;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			if (u==x||v==x)
				deg++;
		}
		//debug(deg);
		if (deg<=1) {
			printf("Ayush\n");
		}
		else {
			if (n%2==0)
				printf("Ayush\n");
			else 
				printf("Ashish\n");
		}
	} 
}