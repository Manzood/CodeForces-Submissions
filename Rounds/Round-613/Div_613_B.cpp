#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		int flag=0;
		scanf("%lld",&n);
		long long sum=0;
		vector <long long> prefixsum;
		while(n--)
		{
			long long x;
			scanf("%lld",&x);
			sum+=x;
			prefixsum.push_back(sum);
		}
		int current=0;
		for (int i=0;i<prefixsum.size()-1;i++)
		{
			if(prefixsum[i]<=0)
				flag=1;
			//printf("%lld\n",prefixsum[i]);
		}
		for (int i=prefixsum.size()-2;i>=0;i--)
		{
			if (sum-prefixsum[i]<=0)
				flag=1;
			//printf("%lld",sum-prefixsum[i]);
		}
		if (flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
}