#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector <int> b(n);
	for (int i=0;i<n;i++) {
		scanf("%d",&b[i]);
	}
	vector <int> a(n);
	a[0]=b[0];
	int max=0;
	for (int i=0;i<n;i++) {
		a[i]=b[i]+max;
		printf("%d ",a[i]);
		if (a[i]>max)
			max=a[i];
	}
}