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
		vector <int> ans;
		int index=-1;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		for (int i=0;i<n-1;i++) {
			if (i==0) {
				ans.push_back(a[i]);
				index++;
			}
			else {
				if (a[i]>ans[index]) {
					if (a[i+1]<=a[i]) {
						ans.push_back(a[i]);
						// debug(a[i]);
						// debug(a[i+1]);
						index++;
					}
				}
				else if (a[i]<ans[index]) {
					if (a[i+1]>=a[i]) {
						ans.push_back(a[i]);
						index++;
					}
				}
			}
		}
		if (a[n-1]!=ans[ans.size()-1]) 
			ans.push_back(a[n-1]);
		printf("%d\n",(int)ans.size());
		for (int i=0;i<ans.size();i++) {
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
}

