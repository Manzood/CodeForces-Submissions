#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		vector <int> cnt(n+1,0);
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		int ans=0;
		for (int i=0;i<n;i++) {
			int sum=0;
			for (int j=i;j<n;j++) {
				sum+=a[j];
				if (j-i>=1 && sum<=n) {
					ans+=cnt[sum];
					cnt[sum]=0;
				}
			}
		}
		printf("%d\n",ans);					
	}
}

