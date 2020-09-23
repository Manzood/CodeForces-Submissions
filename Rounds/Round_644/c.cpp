#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		int even=0;
		int odd=0;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (a[i]%2==0)
				even++;
			else 
				odd++;
		}
		sort(a.begin(),a.end());
		int count=0;
		for (int i=1;i<n;i++) {
			if (a[i]-a[i-1]==1)
				count++;
		}
		//debug(even);
		if (even%2==1) {
			if (count>0)
				printf("YES\n");
			else 
				printf("NO\n");
		}
		else 
			printf("YES\n");
	}
}