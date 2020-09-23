#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[n];
		int flag=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for (int i=0;i<n;i++)
		{
			for (int j=i+2;j<n;j++)
				if (a[i]==a[j])
					flag=1;
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}