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
		int n,k;
		cin>>n>>k;
		int i=1;
		int current=1;
		while (current<k) {
			++i;
			current+=i;
		}
		int firstpos=n-i;
		int lastpos;
		if (i!=1) {
			current-=i;
			lastpos=n-(k-current)+1;
		}
		else {
			lastpos=firstpos+1;
		}
		for (int i=1;i<=n;i++) {
			if (i==firstpos||i==lastpos)
				printf("b");
			else
				printf("a");
		}
		printf("\n");
	}
}