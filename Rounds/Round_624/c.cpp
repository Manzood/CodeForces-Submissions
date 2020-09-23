#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int alpha[26];
	for (int i=0;i<26;i++)
		alpha[i]=0;
	while(t--)
	{
		int n,m,weightage=1;
		scanf("%d%d",&n,&m);
		int p[m];
		char s[n];
		int pos[n];
		for (int i=0;i<n;i++)
			pos[i]=0;
		scanf("%s",s);
		//printf("%s\n",s);
		for (int i=0;i<m;i++)
		{
			scanf("%d",&p[i]);
			pos[p[i]-1]++;
		}
		for (int i=n-1;i>=0;i--)
		{
			if (pos[i])
				weightage+=pos[i];
			alpha[s[i]-'a']+=weightage;
		}
		//for (int i=0;i<n;i++)
		//	alpha[s[i]-'a']++;
		for (int i=0;i<26;i++)
		{
			printf("%d ",alpha[i]);
			alpha[i]=0;
		}
		printf("\n");
	}
}