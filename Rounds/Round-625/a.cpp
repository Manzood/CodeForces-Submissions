#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n, a=0, b=0;
	cin>>n;
	int rbcoder[n];
	int bsolver[n];
	for (int i=0;i<n;i++)
		cin>>rbcoder[i];
	for (int i=0;i<n;i++)
		cin>>bsolver[i];
	for (int i=0;i<n;i++)
	{
		if (rbcoder[i]==1 && bsolver[i]==0)
			a++;
		else if (bsolver[i]==1 && rbcoder[i]==0)
			b++;
	}
	//printf("%d %d %d\n",a,b,(b/a));
	if (a>0)
	{
		printf("%d\n",(b/a)+1);
	}
	else
		printf("-1\n");
}