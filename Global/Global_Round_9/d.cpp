#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		vector <int> count(n+1);
		vector <int> ans;
		bool sorted=false;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			count[i]=0;	
		}
		count[n]=0;
		// make a permutation from 0 to n-1, or otherwise from 1 to n
		bool one=false;
		int mex=0;
		for (int i=0;i<n;i++) {
			count[a[i]]++;
		}
		while (count[mex]>0) mex++;
		// debug(mex);
		int prev=-1;
		while (sorted==false) {
			sorted=true;
			for (int i=1;i<n;i++) {
				if (a[i]<a[i-1] || a[i]==0) {
					sorted=false;
					break;
				}
			}
			if (a[0]==0) sorted=false;
			if (sorted==true) break;
			if (mex==0) {
				for (int i=0;i<n;i++) {
					if (a[i]!=i+1) {
						count[0]++;
						count[a[i]]--;
						a[i]=0;
						ans.push_back(i);
						break;
					}		
				}
			}
			else {
				count[mex]++;
				count[a[mex-1]]--;
				a[mex-1]=mex;
				ans.push_back(mex-1);
			}
			for (int i=0;i<=n;i++) {
				if (count[i]==0) {
					mex=i;
					break;
				}
			}
			// debug(mex);
			// for (int i=0;i<n;i++) {
			// 	printf("%d ",a[i]);
			// }
			// printf("\n");
		}
		printf("%d\n",(int)ans.size());
		for (int i=0;i<ans.size();i++) {
			printf("%d ",ans[i]+1);
		}
		printf("\n");
		// for (int i=0;i<n;i++) {
		// 	printf("%d ",a[i]);
		// }
		// printf("\n");
	}
}
