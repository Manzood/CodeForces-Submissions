#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	int n;
	while(t--)
	{
		scanf("%d", &n);
		vector <int> a(n);
		int sum=0;
		int test=0;

		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			sum+=a[i];
		}
		int start=0;
		int end=n-1;

		for (int i=0;i<n && test==0;i++)
		{
			if (sum==0)
			{
				printf("%d\n",n-i);
				for (int j=start;j<=end;j++)
					printf("%d ", j+1);
				printf("\n");
				test=1;
			}
			else if (sum>0)
			{
				sum-=a[end];
				end--;
			}
			else
			{
				sum-=a[start];
				start++;
			}
		}
	}
}