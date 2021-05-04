//Can be used to test solutions of multiple problems
#include"bits/stdc++.h"
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));
    int t = 1;
    printf("%d\n", t);
	int n=rand(1, 2);
    n *= 2;
	printf("%d ",n);
    int l = rand (1, n);
    printf("%d %d\n", l, n - l);
	for (int i=0;i<n;i++)
	{
		int x;
        x=rand(1, n);
		printf("%d ",x);
	}
	puts("");
}
