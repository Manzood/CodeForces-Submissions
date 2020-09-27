#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n;
	cin>>n;
	vector <int> a(n);
	set <int> nums;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		nums.insert(a[i]);
	}
	int next, mex=0;
	vector <int> ans;
	vector <int> gaps;
	int start=0;
	while (start<=n) {
		if (nums.count(start)) {
			start++;
		}
		else {
			gaps.push_back(start++);
		}
	}
	next=gaps[0];
	int index=0;
	set <int> inserted;
	for (int i=0;i<n;i++) {
		ans.push_back(next);
		inserted.insert(next);
		if (next==gaps[index])
			index++;
		if (next==mex) {
			while (inserted.count(++mex));
		}
		if (a[i]==mex && i<n-1 && a[i+1]>mex) 
			next=a[i];
		else {
			next=gaps[index];
		}
	}
	for (int i=0;i<n;i++) {
		printf("%d ",ans[i]);
	}
	printf("\n");
}

// 0 0 0 0 0 5
// 1 2 3 4 4 0