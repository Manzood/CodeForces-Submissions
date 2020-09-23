#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n;
	cin>>n;
	printf("%d\n",(7+(3*(n-1))));
	printf("0 0\n1 0\n0 1\n1 1\n2 1\n1 2\n2 2\n");
	int start=3;
	for (int i=0;i<n-1;i++) {
		printf("%d %d\n%d %d\n%d %d\n",start,start,start-1,start,start,start-1);
		start++;
	}
}