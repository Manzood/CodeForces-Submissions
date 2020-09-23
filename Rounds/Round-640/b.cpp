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
		int n,k;
		scanf("%d %d",&n,&k);
		if (n%2==0) {
			if (k>n)
				printf("NO\n");
			else if (k%2!=0) {
				if (n<(2*k))
					printf("NO\n");
				else {
					printf("YES\n");
					for (int i=0;i<k-1;i++)
						printf("2 ");
					printf("%d\n",(n-2*(k-1)));
				}
			}
			else {
				printf("YES\n");
				for (int i=0;i<k-1;i++) 
					printf("1 ");
				printf("%d\n",(n-(k-1)));
			}
		}
		else {
			if (k>n)
				printf("NO\n");
			else if (k%2==0)
				printf("NO\n");
			else {
				printf("YES\n");
				for (int i=0;i<k-1;i++) 
					printf("1 ");
				printf("%d\n",(n-(k-1)));
			}
		}
	}
}