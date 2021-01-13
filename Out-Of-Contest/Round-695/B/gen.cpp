//Can be used to test solutions of multiple problems
#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));
    printf("1\n"); // test case
    int n=rand(2,8);
    printf("%d\n",n);
    for (int i=0;i<n;i++) {
        int x;
        x=rand(1, 8);
        printf("%d ",x);
    }
    puts("");
}
