#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>

using namespace std;

#define debug(x) cout<<x<<endl:
#define MOD 998244353;

int main() {
	long long n,k;
	cin>>n>>k;
	vector <int> numbers(n);
	for (int i=0;i<n;i++) {
		scanf ("%d",&numbers[i]);
	}
	long long sum=((n)*(n+1))/2;
	sum-=((n-k)*(n-k+1))/2;
	int ans=1;
	long long counter=0;
	int totalmax=0;
	bool shouldbechecking=0;
	for (int i=0;i<n;i++) {
		if (numbers[i]>(n-k)) {
			shouldbechecking=true;
			totalmax++;
			if (counter>0) {
				ans=ans*counter;
				ans%=MOD;
			}
			counter=0;
		}
		if (shouldbechecking) {
			counter++;
		}
		if (totalmax==k) {
			shouldbechecking=false;
		}
	}
	printf("%lld %d\n",sum,ans);
}