#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
using namespace std;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		int summands[5];
		int count=0;
		int mult=1;
		int ans=0;
		while (n) {
			summands[count]=n%10;
			if (summands[count]!=0)
				ans++;
			count++;
			n/=10;
			mult*=10;
		}
		if (count!=0)
			mult/=10;
		printf("%d\n",ans);
		for (int i=count-1;i>=0;i--) {
			if (summands[i]!=0)
				printf("%d ",summands[i]*mult);
			mult/=10;
		}
		printf("\n");
	}
}