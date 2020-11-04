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
	set <int> used;
    int n = rand(2, 10);
    printf("%d\n", n);
    printf("1 ");
	for (int i=0;i<n-1;i++)
	{
		int x;
		do {
			x=rand(2,n);
		} while(used.count(x));
		used.insert(x);
		printf("%d ",x);
	}
	puts("");
}
