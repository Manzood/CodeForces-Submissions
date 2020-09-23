#include<cstdio>
#include<iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	int n;
	while (t--) {
		scanf("%d",&n);
		if (n==1) {
			printf("-1\n");
		}
		else {
			printf("2");
			for (int i=1;i<n;i++) {
				printf("3");
			}
			printf("\n");
		}
	}
}