#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	long long n,a,b,k;
	scanf("%lld %lld %lld %lld",&n,&a,&b,&k);
	long long hp;
	int flag;
	int points=0;
	vector<long long> diff;
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&hp);
		int x;
		if (hp%(a+b)>0)
			x=hp%(a+b);
		else
			x=hp-(hp/(a+b)-1)*(a+b);
		//printf("%d\n",x);
		if (x>a)
		{
			if ((x%a)>0)
				diff.push_back((x/a)+1);

			else
				diff.push_back(x/a);
		}
		else
			points++;
	}
	sort(diff.begin(),diff.end());
	for (int i=0;i<diff.size()&&k>0;i++)
	{
		//printf("%lld ",diff[i]);
		k-=diff[i];
		points++;
	}
	printf("%d",points);
}