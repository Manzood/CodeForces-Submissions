#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int swap(int *a, int *b)
{
	//printf("swapping %d %d\n", *a, *b);
	int temp=*b;
	*b=*a;
	*a=temp;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int flag=1;
		int m,n;
		cin>>n>>m;
		int a[n];
		int p[m];
		int pos[n];
		for(int i=0;i<n;i++)
			pos[i]=0;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&p[i]);
			pos[p[i]-1]=1;
		}
		//for (i=0;i<n;i++)
		for(int i=n-1;i>=0 && flag;i--)
		{
			for(int j=i;j<n-1 && flag;j++)
			{
				if (a[j]>a[j+1] && pos[j])
					swap(&a[j],&a[j+1]);
				else if (a[j]>a[j+1])
					flag=0;
				else
					break;
			}
		}

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}