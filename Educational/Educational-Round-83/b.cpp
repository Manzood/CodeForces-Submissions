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
		vector <int> a(n);
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a.begin(),a.end(),greater<int>());
		for (int i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}