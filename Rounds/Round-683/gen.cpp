//Can be used to test solutions of multiple problems
#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[])
{
	srand(atoi(argv[1]));
	int n=rand(2,10);
    int m = rand(2, 10);
	printf("%d %d\n",n, m);
	for (int i=0;i<n;i++)
	{
		int x;
        x=rand(0,2);
		printf("%c",x + 'a');
	}
    printf("\n");
	for (int i=0;i<m;i++)
	{
		int x;
        x=rand(0,2);
		printf("%c",x + 'a');
	}
	puts("");
}
