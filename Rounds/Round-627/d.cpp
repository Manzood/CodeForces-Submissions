#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	long long n;
	cin>>n;
	vector <long long> a(n);
	long long temp;
	for (int i=0;i<n;i++)
	 	scanf("%lld",&a[i]);
	for (int i=0;i<n;i++)
	{
	 	scanf("%lld",&temp);
		a[i]-=temp;
	}
	sort(a.begin(),a.end());
	int loc=-1;
	for (int i=0;i<n && a[i]<=0;i++)
		loc=i;
	long long ans=0;
	int lastpos=n-1;
	for (int i=0;i<=loc;i++)
	{
	 	int j=lastpos;
	 	while((a[j]+a[i])>0 && j>i)
	 		j--;
	 	lastpos=j;
	 	ans+=n-1-lastpos;
	}
	//printf("%lld",ans);	
	if (loc>-1)
		ans+=((n-1-loc)*(n-loc-2))/2;
	else
	{
		for (int i=0;i<n && loc==-1;i++)
			if (a[i]>0)
				loc=i;
		if (loc>-1)
			ans+=((n-loc)*(n-loc-1))/2;
	}
	printf("%lld",ans);
}