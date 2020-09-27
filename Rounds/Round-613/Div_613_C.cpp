#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int checklcm (int n1, int n2)
{
	int m;
    m = max(n1,n2);
    do
    {
        if (m % n1 == 0 && m % n2 == 0)
            break;
        else
            m++;
    } 
    while (true);
    
    return m;
}

int main()
{
	long long x;
	scanf("%lld",&x);
	long long final=x;
	vector <long long> factors;
	int len=0;
	int i=2;
	bool isprime;
	while ((x%i)==0 && x>1)
	{
		x=x/i;
		factors.push_back(i);
		len++;
	}
	i++;
	while(x>1)
	{
		isprime=true;
		for (int j=3;j<=i/2;j+=2)
			if ((i%j) ==0)
				isprime = false;
		while((x%i)==0 && isprime==true)
		{
			x=x/i;
			factors.push_back(i);
			len++;
		}
		i+=2;
	}
	long long l=1,r=final;
	long long minl=l, minr=r;
	sort(factors.begin(),factors.end());
	
	int temp=x;
	//printf("%d\n",len);
	for (int i=len;i>0;i--)
	{
		l=1;
		for (int j=0;j<i;j++)
		{
		l=l*factors[j];
		if ((max(l,r) < max(minl,minr)) && checklcm(l,r)==final)
		{
			minl=l;
			minr=r;
		}
		r=r/factors[i];
		}
	}
	printf("%lld %lld", minl, minr);
	return 0;
}