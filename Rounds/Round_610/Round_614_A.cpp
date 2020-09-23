#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,s,k;
		scanf("%d %d %d", &n, &s, &k);
		vector <int> a(n);
		for (int i=0;i<n;i++)
			a[i]=1;
		int b;
		while (k--)
		{
			scanf ("%d",&b);
			a[b-1]=0;
		}
		s--;
		int i=s;
		int ans=0;
		while (a[i]!=1&&i!=n-1)
		{
			i++;
			if (a[i]==1)
				ans=i-s;
		}
		i=s;
		while(a[i]!=1&&i!=0)
		{
			i--;
			if (a[i]==1)
				if ((s-i)<ans)
					ans=s-i;
		}
		printf("%d\n",ans);
	}
}	