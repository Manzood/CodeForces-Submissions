#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	scanf ("%d\n", &n);
	string s;
	int r=0,l=0;
	getline(cin,s);
	for (int i=0;i<n;i++)
	{
		if(s[i]=='R')
			r++;
		else
			l++;
	}
	printf("%d",r+l+1);
	return 0;
}