#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	vector <int> a;
	vector <int> b;
	vector <int> both;
	int acount=0, bcount=0;
	for (int i=0;i<n;i++) {
		int t, first, second;
		scanf("%d%d%d",&t,&first,&second);
		if (first && second) {
			both.push_back(t);
			acount++;
			bcount++;
		}
		else if (first) {
			a.push_back(t);
			acount++;
		}
		else if (second) {
			b.push_back(t);
			bcount++;
		}
	}
	sort(both.begin(),both.end());
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int bind=0, aind=0, bothind=0;
	int ans=0, count=0;
	if (acount<k || bcount<k) {
		ans=-1;
		count=k;
	}
	while (count<k) {
		if (aind==a.size() || bind==b.size() || (bothind<both.size() && both[bothind]<a[aind]+b[bind])) {
			ans+=both[bothind++];
		}
		else {
			ans+=a[aind++];
			ans+=b[bind++];
		}
		count++;
	}
	printf("%d\n",ans);
}