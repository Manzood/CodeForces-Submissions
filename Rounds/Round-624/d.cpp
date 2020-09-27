#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//flawed approach, as values of a, b and c are also required as the answer. May be a pretty good use of functions, but still overcomplicated and inelegant.

/*
int testcondition(int a, int b, int c, int incra, int incrb, int incrc)
{
	int res=0;
	while(c%b && c>b)
	{
		c+=incrc;
		b+=incrb;
		res+=abs(incrc)+abs(incrb);
	}
	while(b%a && b>a)
	{
		b+=incrb;
		a+=incra;
		res+=abs(incrb)+abs(incra);
	}
	return res;
}
*/

//part of my flawed approach, but the following was a part of main

/*
	int temp;
		r=testcondition(a,b,c,-1,-1,0);
		cout<<"tested once"<<endl;
		
		for (int i=1;i>-3;i-=2)
		{
			for(int j=1;j>-3;j-=2)
			{
				temp=testcondition(a,b,c,i,0,j);
				if (temp<r)
					r=temp;
			}
		}

		for (int i=1;i>-3;i-=2)
		{
			for(int j=1;j>-3;j-=2)
			{
				temp=testcondition(a,b,c,i,j,0);
				if (temp<r)
					r=temp;
			}
		}
*/

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		int r=0;
		scanf("%d%d%d",&a,&b,&c);
		int div1,div2;
		int na=a, nb=b, nc=c;

		if (nc>nb)
		{
			div1=c/b;
			if (((div1+1)*nb-nc) < (nc-(div1*nb)))
			{
				r+=(div1+1)*nb-nc;
				nc=(div1+1)*nb;
				div2=nb/na;
				if ((div2+1)*na)
			}
		}

		printf("%d\n%d %d %d\n",r, a, b, c);
	}
}