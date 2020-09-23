#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int t;
	bool flag=0;
	long long a,b,c,n;
	long long diff,largest;
	scanf("%d",&t);
	while (t--)
	{
		scanf ("%lld %lld %lld %lld",&a,&b,&c,&n);
		largest=max(max(a,b),max(a,c));
		diff=largest-a+largest-b+largest-c;
		if (n<diff)
		{
			printf("NO\n");
		}
		else if ((n-diff)%3!=0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}