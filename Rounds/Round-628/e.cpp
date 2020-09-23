#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int factor(int n)
{
	int sum=0;
	if (n==1)
		return 1;
	while (n%2==0)
	{
		sum+=2;
		n=n/2;
	}
	for (int i=3;i*i<=n || n==3;i+=2)
	{
		while (n%i==0)
		{
			sum+=i;
			n=n/i;
		}
	}
	return sum;
}

int main()
{
	int n;
	cin>>n;
	vector <int> a(n);
	vector <int> prefix(n);
	int min = -1;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		printf("%d",factor(a[i]));
		if (i==0)
			prefix[i]=factor(a[i]);
		else
			prefix[i]+=a[i-1]+factor(a[i]);
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
				if (prefix[i]%2==0 && ....)
					//probably not a solution that will work anyway, and I'm completely out of time for the contest -_-
		}
	}
}