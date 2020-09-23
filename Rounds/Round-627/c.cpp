#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char s[2*100000];
		scanf("%s",s);
		int max=1;
		int current=1;
		int len=strlen(s);
		for (int i=0;i<len;i++)
		{
			if (s[i]=='L')
			{
				current++;
				if (current>max)
					max=current;
			}
			else
				current=1;
		}
		printf("%d\n",max);
	}
}