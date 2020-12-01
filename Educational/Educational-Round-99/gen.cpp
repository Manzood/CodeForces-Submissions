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
    printf("1\n");
	int n=rand(2,8);
    int x = rand(2, 10);
	printf("%d %d\n",n, x);
	for (int i=0;i<n;i++)
	{
        int temp;
        temp = rand (0, 10);
		printf("%d ",temp);
	}
	puts("");
}
