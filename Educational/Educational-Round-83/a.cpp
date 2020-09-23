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
		int n,m;
		scanf("%d%d",&n,&m);
		if (n%m==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}