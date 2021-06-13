#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long check(vector <int> a)
{
	int n=a.size();
	long long count=0;
	for (long i=0;i<n;i++)
	{
		if(a[i]=='1')
			count++;
	}
	if (count!=0){
	if(n%count==0)
		return 1;
	else
		return 0;
	}
	else
		return 0;
}

int main()
{
	vector <int> a;
	vector <int> b;
	long long count=0;
	int c;
	while((c=getchar())!=EOF && c!='\n')
	{
		a.push_back(c);
	}

	int n = a.size();

	for (long i=0;i<n;i++)
	{
		for (long j=0;j<n && n-j>i;j++)
		{
			b=vector <int> (a.begin()+i,a.end()-j);
			if(check(b))
				count++;
		}
	}

	printf("%lld", count);
}