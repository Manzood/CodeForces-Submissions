#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		bool sorted=true;
		int startind=-1;
		bool checkstart=true;
		vector <int> a(n);
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (a[i]!=i+1) {
				sorted=false;
				checkstart=false;
			}
			if (checkstart && a[i]==i+1)
				startind++;
		}
		int endind=n;
		int checkend=true;
		for (int i=n-1;i>=0;i--) {
			if (a[i]==i+1)
				endind--;
			else 
				break;
		}
		bool two=false;
		// debug(startind);
		// debug(endind);
		for (int i=startind+1;i<endind-1;i++) {
			if (a[i]==i+1)
				two=true;
		}
		if (sorted)
			printf("0\n");
		else if (two==false) 
			printf("1\n");
		else 
			printf("2\n");
	}
}