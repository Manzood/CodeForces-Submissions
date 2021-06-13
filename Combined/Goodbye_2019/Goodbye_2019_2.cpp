#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf ("%d", &t);

	int x;
	int n;

	while (t--)
	{
		scanf ("%d", &n);
		int flag=0;

		vector<long> a(n);

		for (int i=0; i<n; i++)
		{
			scanf("%ld", &a[i]);
		}

		for (int i=0;i<n && flag==0;i++)
		{
			b=vector<int> (a.begin()+i,a.end());
			if ((max(b)-min(b))>b.size())
				printf("YES\n%d %d\n", i, )
		}

		if (flag==0)
			printf("NO\n");
	}
}