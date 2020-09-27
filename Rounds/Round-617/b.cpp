#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		long long s;
		scanf("%lld",&s);
		long long spending=0;
		long long temp=0;
		while (s>=10)
		{
			temp=s-(s%10);
			spending+=temp;
			s-=temp;
			s+=temp/10;
		}
		spending+=s;
		printf("%lld\n",spending);
	}
	return 0;
}