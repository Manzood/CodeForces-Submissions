#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define debug(x) cout<<x<<endl;
#define MAX 1e9

//wrong solution-_-
int main () {
	int n,k;
	cin>>n>>k;
	vector <int> a(n);
	int count[MAX];
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	
}