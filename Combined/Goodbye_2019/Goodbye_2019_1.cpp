#include <iostream>
#include <cstdio>
#include <algorithm>

int main()
{
	int t;

	scanf ("%d", &t);

	int n, k1, k2;
	int x;

	int max1, max2;

	while (t--)
	{
		max1 = 0;
		max2 = 0;
		scanf ("%d %d %d", &n, &k1, &k2);

		while (k1--)
		{
			scanf ("%d", &x);
			if (x>max1)
				max1=x;
		}

		while (k2--)
		{
			scanf ("%d", &x);
			if (x>max2)
				max2=x;
		}
		
		if (max1>max2)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}