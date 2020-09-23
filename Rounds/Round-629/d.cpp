#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define debug(x) cout<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> types(n);
		vector <int> cols(n);
		scanf("%d",&types[0]);
		int changed=0;
		int samepos=-1;
		int previous=types[0];
		for (int i=1;i<n;i++) {
			scanf("%d",&types[i]);
			if (types[i]!=types[0])
				changed=1;
			if (types[i]==previous) {
				samepos=i-1;
			}
			previous=types[i];
		}
		if (samepos==-1) {
			if (types[n-1]==types[0])
				samepos=n-1;
		}
		if (changed==0) {
			printf("1\n");
			for (int i=0;i<n;i++) {
				printf("1 ");
			}
		}
		else if (n%2==0) {
			printf("2\n");
			for (int i=0;i<n;i++) {
				if (i%2==0) {
					printf("1 ");
				}
				else
					printf("2 ");
			}
		}
		else {
			if (samepos==-1) {
				printf("3\n");
				for (int i=0;i<n;i++) {
					if (i==n-1) {
						printf("3 ");
					}
					else if (i%2==0) {
						printf("1 ");
					}
					else
						printf("2 ");
				}
			}
			else {
				printf("2\n");
				int current=1;
				for (int i=0;i<n;i++) {
					if (i==samepos) {
						printf("%d ",current);
					}
					else {
						//cout<<"Samepos="<<samepos<<endl;
						printf("%d ",current);
						if (current==1) {
							current=2;
						}
						else {
							current=1;
						}
					}
				}
			}
		}
		printf("\n");
	}
}