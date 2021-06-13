#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	char s[1000];
	scanf("%s", s);
	int len=strlen(s);
	int start=0;
	int end=len-1;
	int k=0;
	vector <int> ans;
	int index;
	while(start<end)
	{
		while(s[start]!='(' && start < len)
			start++;
		while(s[end]!=')' && end > 0)
			end--;
		if (start<end)
		{
			ans.push_back(start);
			ans.push_back(end);
			start++;
			end--;
		}
	}
	index=ans.size();
	sort(ans.begin(),ans.end());
	if (index)
	{
		printf("%d\n",k+1);
		printf("%d\n",index);
		for (int i=0;i<index;i++)
			printf("%d ",ans[i]+1);
		printf("\n");
	}
	else
		printf("%d\n",k);
}