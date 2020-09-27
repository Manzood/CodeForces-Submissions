#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int findmax(string s, int len)
{
	int max=0;
	int pos, i=0;
	while(i<len)
	{
		if(s[i]>max)
		{
			max=s[i];
			pos=i;
		}
		i++;
	}
	return pos;
}

int main()
{
	int n;
	cin>>n;
	int maxpos;
	string s;
	cin>>s;
	maxpos = findmax(s, n);
	int count=0;
	while (s[maxpos]>'0' && n>1)
	{
	if (maxpos>0 && maxpos<n-1)
	{
		if ((s[maxpos]-s[maxpos+1])==1 || (s[maxpos]-s[maxpos-1]==1))
		{
			s.erase(maxpos,1);
			n--;
			count++;
		}
		else
		{
			s[maxpos]='0';
		}
		maxpos=findmax(s,n);
		//printf("%c\n",s[maxpos]);
		//cout<<s<<endl;
	}
	else
	{
		if (maxpos==0)
		{
			if ((s[maxpos]-s[maxpos+1])==1)
			{
				s.erase(maxpos,1);
				n--;
				count++;
			}
			else
				s[maxpos]='0';
		}
		else if (maxpos==n-1)
		{
			if ((s[maxpos]-s[maxpos-1]==1))
			{
				s.erase(maxpos,1);
				n--;
				count++;
			}
			else
				s[maxpos]='0';
		}
		maxpos=findmax(s,n);
		//printf("%c\n",s[maxpos]);
		//cout<<s<<endl;
	}
	}
	printf("%d\n",count);
}