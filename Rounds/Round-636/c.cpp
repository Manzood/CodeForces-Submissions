#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		int state;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		if(a[0]<0) {
			state=1;
		}
		else {
			state=-1;
		}
		int maxneg=0,maxpos=0;
		long long ans=0;
		for (int i=0;i<n;i++) {
			if (a[i]<0) {
				if (state==1) {
					ans+=maxpos;
					maxneg=a[i];
					state=-1;
				}
				else {
					if (a[i]>maxneg) {
						maxneg=a[i];
					}
				}	
			}
			else {
				if (state==-1) {
					state=1;
					maxpos=a[i];
					ans+=maxneg;
				}
				else {
					if (a[i]>maxpos) {
						maxpos=a[i];
					}
				}
			}
		}
		if (state==-1) {
			ans+=maxneg;
		}
		else {
			ans+=maxpos;
		}
		printf("%lld\n",ans);
	}
}