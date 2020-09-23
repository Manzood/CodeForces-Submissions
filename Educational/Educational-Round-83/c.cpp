#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n,k;
		long long temp;
		scanf("%d%d",&n,&k);
		bool flag=1;
		vector <long long> used(1000);
		for (int i=0;i<1000;i++)
			used[i]=0;
		int count=0;
		for (int i=0;i<n;i++)
		{
			scanf("%lld",&temp);
			//printf("%lld\n",temp);
			count=0;
			while(temp>0 && flag==1)
			{
				//printf("%lld\n",temp);
				if (k==0)
					flag=0;
				else if (k==1)
				{
					if (temp!=0 && used[count]==0)
					{
						temp-=1;
						used[count]++;
					}
					else if (temp!=0)
						flag=0;
				}
				else if (temp%k==0)
				{
					temp/=k;
					count++;
				}
				else if (temp%k==1 && used[count]==0)
				{
					temp-=1;
					used[count]=1;
				}
				else
					flag=0;
			}
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}