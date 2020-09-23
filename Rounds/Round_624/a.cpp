#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

#define debug(x) cout<<#x<<" = "<<endl;

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		int moves=0;
		scanf("%lld%lld",&a,&b);
		if (b>a)
		{
			if ((b-a)%2==0)
				moves=2;
			else
				moves=1;
		}
		else if (b<a)
		{
			if ((a-b)%2==0)
				moves=1;
			else
				moves=2;
		}
		else
			moves=0;
		printf("%d\n",moves);
	}
}
