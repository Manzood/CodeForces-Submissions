#include <cstdio>
#include <algorithm>
#include<vector>

int main()
{
	int t,n,c;
	scanf ("%d", &t);
	while (t--)
	{
		int sum,x,diff,s;
		scanf("%d",&n);
		vector <int> a(n);

		scanf("%d", &x);
		sum=c;
		x=c;
		s=0;

		for (int i=1;i<n;i++)
		{
			scanf("%d", &a[i]);
			sum+=a[i];
			x^=a[i];
		}

		diff=sum-(2*x);

		if(diff!=0)
		{
			
		}
	}
}