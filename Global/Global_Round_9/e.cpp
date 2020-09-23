#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

void swap (int *a, int *b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

int main() {
	int n;
	scanf("%d",&n);
	vector <int> a(n);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	vector <pair <int, int> > ans;
	set <pair <int, int> > inv;
	for (int i=0;i<n;i++) {
		for (int j=n-1;j>i;j--) {
			if (a[i]>a[j]) {
				inv.insert(make_pair(i,j));
			}
		}
	}
	bool possible=true;
	for (auto x: inv) {
		swap (a[x.first],a[x.second]);
		ans.emplace_back(x.first,x.second);
	}
	debug(a[0]);
	for (int i=1;i<n;i++) {
		if (a[i]<a[i-1])
			possible=false;
		debug(a[i]);
	}
	if (possible) {
		printf("%d\n",(int)ans.size());
		for (int i=0;i<ans.size();i++) {
			printf("%d %d\n", ans[i].first+1, ans[i].second+1);
		}
}
	else {
		printf("-1");
	}
}