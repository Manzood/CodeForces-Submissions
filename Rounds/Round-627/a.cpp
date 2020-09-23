#include<cstdio>
#include<iostream>
#include<algorithm>
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
		int first,x;
		scanf("%d",&first);
		int flag=1;
		for (int i=1;i<n;i++)
		{
			scanf("%d",&x);
			if ((x-first)%2!=0)
				flag=0;
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}	
}