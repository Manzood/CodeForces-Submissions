#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define debug(x) cout<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int a,b;
		cin>>a>>b;
		if (a%b==0)
			printf("0\n");
		else {
			printf("%d\n",b-(a%b)); 
		}
	}
}