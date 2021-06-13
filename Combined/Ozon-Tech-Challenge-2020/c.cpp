#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
 
using namespace std;
 
int main()
{
	int n,m;
	cin>>n>>m;
	vector <long long> a(n);
	for (int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	long long prod=1;
	if (n>m)
		printf("0");
	else
	{
		for (int i=0;i<n-1;i++)
		{
			for (int j=i+1;j<n;j++)
			{
				//if (prod==0)
				//	printf("%d %d\n",i,j);
				prod = prod * (abs(a[i]-a[j])%m);
				prod = prod % m;
				//printf("%lld\n",prod);
			}
			prod = prod % m;
			if (prod == 0)
			{
				break;
			}
		}
		printf("%lld", prod);
	}
}