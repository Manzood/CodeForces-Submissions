#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,y;
		int low=0;
		int posx=0;
		int posy=0;
		int maxx=0;
		bool flag=0;
		scanf ("%d",&n);
		vector <vector <int> > a(1001);
		for (int i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			a[x].push_back(y);
		}
		for (int i=0;i<1001;i++)
		{
			sort(a[i].begin(),a[i].end());
			int temp=a[i].size();
			if (temp>0)
			{
				if (a[i][0]>=low)
					low=a[i][temp-1];
				else
				{
					flag=1;
				}
				maxx=i;
			}
		}
		if (flag==1)
			printf("NO\n");
		else
		{
			printf("YES\n");
			for (int i=0;i<=maxx;i++)
			{
				for (int j=0;j<a[i].size();j++)
				{
					while (posy<a[i][j])
					{
						posy++;
						printf("U");
					}
				}
				if (i!=maxx)
					printf("R");
			}
			printf("\n");
		}
	}
}