#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define N 10000000

int main() {
	int n;
	scanf("%d",&n);
	int a;
	vector <pair <int,int> > ans;
	map <int, pair<int,int> > mp;
	vector <int> primes(N);
	for (int i=0;i<N;i++) {
		primes[i]=1;	
	}
	for (int i=2;i*i<N;i++) {
		if (primes[i]) {
			for (int j=2*i;j<N;j+=i) {
				primes[j]=0;
			}
		}
	}
	for (int i=0;i<n;i++) {
		scanf("%d",&a);
		bool found=false;
		if (primes[a]) {
			ans.emplace_back(-1,-1);
			mp[a]=make_pair(-1,-1);
			continue;
		}
		if (mp.count(a)) {
			ans.emplace_back(mp[a]);
			continue;
		}
		for (int j=2;j*j<=a;j++) {
			if (a%j==0 && a/j>1) {
				if (__gcd(j+a/j,a)==1)
					found=true;
			}
			if (found) {
				ans.emplace_back(j,a/j);
				mp[a]=make_pair(j,a/j);
				break;
			}
		}
		if (!found) {
			ans.emplace_back(-1,-1);
			mp[a]=make_pair(-1,-1);
		}
	}
	for (int i=0;i<n;i++) {
		printf("%d ",ans[i].first);
	}
	printf("\n");
	for (int i=0;i<n;i++) {
		printf("%d ",ans[i].second);
	}
}	