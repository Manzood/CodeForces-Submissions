#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main()
{
	int q,x;
	scanf("%d %d",&q,&x);
	int c;
	vector <int> a;
	while (q--)
	{
		scanf ("%d",&c);
		c=c%x;
		//printf("%d\n",c);
		int flag=0;
		for (int i=0;i<a.size() && flag==0;i++)
		{
			if (a[i]==c)
			{
				c+=x;
				//printf("%d\n",c);
			}	
			else if (a[i]>c)
			{
				a.insert(a.begin()+i,c);
				flag=1;
			}
		}
		if (flag==0)
			a.push_back(c);
		int test=0;
		for (int i=0;i<a.size();i++)
		{
			//printf("%d ",a[i]);
			if (a[i]>test)
				break;
			else if (a[i]==test)
				test++;
		}
		printf("%d\n",test);
	}
}