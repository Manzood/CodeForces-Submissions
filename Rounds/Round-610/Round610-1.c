#include <stdio.h>

int main()
{
	int t, a, b, c, r;
	int ans, common, test;

	scanf ("%d", &t);

	while (t--)
	{
		ans = 0;
		common = 0;
		test = 1;

		scanf ("%d %d %d %d", &a, &b, &c, &r);

		if (a>b)
		{
			a = a+b;
			b = a-b;
			a = a-b;
		}

		if ((c-r)>a && c+r<=b)
		{
			common+=2*r;
		}

		else if ((c+r)>a && (c+r)<=b) 
		{
			common += (c+r)-a;
		}

		else if ((c-r)<=b && (c-r)>a)
		{
			common+=b-(c-r)+1;
		}

		else if (c-r<a && c+r>=b)
		{
			test = 0;
			ans = 0;
		}

		if (test)
			ans = b-a-common;

		printf ("%d\n", ans);
	}	
}