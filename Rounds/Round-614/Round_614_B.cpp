#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	double ans=0;
	for (int i=1;i<=n;i++)
	{
		ans+=(double)1/i;
	}
	printf("%.12lf",ans);
}