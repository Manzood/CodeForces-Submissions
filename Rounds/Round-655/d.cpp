#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector <int> b;
	for (int i = 0; i < n; i += 2) 
		b.push_back(a[i]);
	for (int i = 1; i < n; i += 2) 
		b.push_back(a[i]);
	for (int i = 0; i < n; i += 2) 
		b.push_back(a[i]);
	int count = 0;
	long long s = 0;
	long long m = 0;
	for (int i = 0; i < b.size(); i++) {
		if (count < (n+1)/2) {
			s += b[i];
			count++;
		}
		else {
			s -= (b[i-count]);
			s += b[i];
		}
		m = max (s, m);
	}
	printf("%lld\n", m);
}

