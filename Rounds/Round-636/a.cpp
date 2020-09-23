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
		int start=3;
		int next=4;
		while (n%start!=0) {
			start+=next;
			next*=2;
		}
		printf("%d\n",n/start);
	}
}