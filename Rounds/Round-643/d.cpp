#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n,s;
	scanf("%d %d",&n,&s);
	int sum=0;
	vector <int> a(n); 
	for (int i=0;i<n;i++) {
		if (i==n-1)
			a[i]=(s-sum);
		else {
			a[i]=1;
				sum+=1;
		}
	}
	int k;
	if (a[n-1]<=sum+1) {
		printf("NO\n");
	}
	else {
		k=a[n-1]-1;
		printf("YES\n");
		for (int i=0;i<n;i++) {
			printf("%d ",a[i]);
		}
		printf("\n%d\n",k);
	}
}