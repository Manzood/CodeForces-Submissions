#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		int sum=0, flag=0;
		int parity;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			parity=a[0]%2;
			if ((a[i]%2) != parity)
			{
				flag=1;
			}
			sum+=a[i];
		}
		if (sum%2==1)
			printf("YES\n");
		else if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}