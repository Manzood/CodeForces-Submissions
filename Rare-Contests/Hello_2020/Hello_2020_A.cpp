#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	char s[20][10];
	char t[20][10];
	int i, j;
	char c;
	int tsize[20],ssize[20];
	int q,y;
	int tc,sc;

	i=0;
	getchar();
	while(i<n)
	{
		j=0;
		while(((c=getchar())!=' ') && (c!='\n') && (c!=EOF))
		{
			s[i][j]=c;
			j++;
		}
		ssize[i]=j;
		i++;
	}

	i=0;
	while(i<m)
	{
		j=0;
		while(((c=getchar())!=' ') && (c!='\n') && (c!=EOF))
		{
				t[i][j]=c;
				j++;
		}
		tsize[i]=j;
		i++;
	}

	cin>>q;
	sc=0;
	tc=0;

	while (q--)
	{
		cin>>y;
		y--;
		sc=y%n;
		tc=y%m;
		for (j=0;j<ssize[sc];j++)
		{
			printf("%c",s[sc][j]);
		}
		for (j=0;j<tsize[tc];j++)
		{
			printf("%c",t[tc][j]);
		}
		cout<<endl;
	}

	return 0;
}