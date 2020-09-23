#include <iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	long long n,l,c,x;
	cin>>n;
	vector <long long> check;
	vector <long long> end;
	vector <long long> start;
	int flag;
	long long m=n;
	long long ans=0;
	long long i=0;

	while(m--)
	{
		flag=0;
		cin>>l;
		l--;
		cin>>c;
		start.push_back(c);
		x=c;
		while(l--)
		{
			cin>>c;
			if (x<c)
			{
				flag=1;
			}
			x=c;
		}
		end.push_back(c);
		check.push_back(flag);
		i++;
	}

	vector <long long> unstarts;
	vector <long long> unends;


	for (int i=0;i<check.size();i++)
	{
		if (check[i]==1)
		{
			ans+=2*n;
		}
		else
		{
			//printf("%lld %lld\n",start[i],end[i]);
			unstarts.push_back(start[i]);
			unends.push_back(end[i]);
		}
	}

	sort(unstarts.begin(),unstarts.end());
	sort(unends.begin(), unends.end());

	int lower=0;
	int upper=unstarts.size();
	int key;

	for (int i=0; i<unends.size();i++)
	{
		upper=unstarts.size();
		key=(lower+upper)/2;
		while ((lower-upper)>1)
		{
			if (unstarts[key]>unends[i])
				upper=key;
			else if (unstarts[key]<unends[i])
				lower=key;
			else
				lower=upper;
			key=(lower+upper)/2;
			printf("%d ",key);
		}
		lower=key;
		ans+=key;
		printf("\n");
	}
	int noo=unends.size();

	printf("\n%d\n", noo);

	printf("%lld\n", ans);
}