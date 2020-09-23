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
		vector <int> a(n);
		vector <int> b(n);
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (int i=0;i<n;i++)
			scanf("%d",&b[i]);
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for (int i=0;i<n;i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
		for (int i=0;i<n;i++)
		{
			printf("%d ", b[i]);
		}
		printf("\n");
	}
}