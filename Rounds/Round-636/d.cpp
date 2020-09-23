#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int getans(vector <int> a, int min) {
	

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n, k;
		int min;
		int temp;
		scanf("%d %d",&n,&k);
		//first pass, scanf
		vector <int> a(n);
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (i==n/2) {
				min=a[i]+a[i-1];
			}
			else if (i>n/2) {
				temp=a[i]+a[n-i-1];
				if (temp<min) {
					temp=min;
				}
			}
		}
		int ans=getans(a,min);
