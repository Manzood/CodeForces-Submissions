#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		long long x;
		set <long long, greater <long long> > a;
		scanf("%lld",&n);
		for (long long i=0;i<n;i++)
		{
			scanf("%lld",&x);
			a.insert(x);
		}
		long long ans = a.size();
		printf("%lld\n",ans);
	}
}