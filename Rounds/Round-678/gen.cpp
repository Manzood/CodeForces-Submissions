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
	int n=rand(2,5);
	printf("%d\n",n);
	for (int i=2;i<=n;i++)
	{
		int x;
        x=rand(1,i-1);
		printf("%d ",x);
	}
    printf("\n");
    for (int i = 0; i < n; i++) {
        int x;
        x = rand(1, 20);
        printf("%d ", x);
    }
	puts("");
}

