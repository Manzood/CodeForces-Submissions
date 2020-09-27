#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	//prefix sum problem
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d\n",&n);
		char s[n];
		vector<long long> prefix(n+1);
		int ans1,ans2;
		
		prefix[0]=0;
		
		for (int i=0;i<n;i++)
		{
			scanf("%c",&s[i]);
			if (s[i]=='U')
				prefix[i+1]=prefix[i]+1;
			else if (s[i]=='D')
				prefix[i+1]=prefix[i]-1;
			else if (s[i]=='R')
				prefix[i+1]=prefix[i]+30;
			else
				prefix[i+1]=prefix[i]-30;
		}
		int min=n+1;
		for (int i=0;i<=n;i++)
		{
			//printf("%lld ",prefix[i]);
			for (int j=1;j<min && (i+j)<=n;j++)
			{
				if (prefix[i]==prefix[j+i])
				{
					if (j<min)
					{
						//printf("\nchanging = %lld %lld\n",prefix[i],prefix[i+j]);
						min=j;
						ans1=i+1;
						ans2=ans1+j-1;
					}
				}
			}
		}
		if (min==n+1)
			printf("-1\n");
		else
			printf("%d %d\n",ans1,ans2);
	}
	return 0;
}