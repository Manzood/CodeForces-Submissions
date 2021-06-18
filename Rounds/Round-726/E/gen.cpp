// Todo: make a better generator, eventually
#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[])
{
	srand (atoi (argv[1]));
    // test cases
    // printf("1\n");
	int n = rand (2, 30);
    int k = rand (n, 100);
	printf ("%d %d", n, k);
    // int m = rand (2, 10);
    // printf(" %d", m);
    printf("\n");

	set <int> used;
	for (int i = 0; i < n; i++) {
		int x;
        x = rand (0, 26);
        // to make x unique, uncomment the following
		// do {
			// x = rand (1, 100);
		// } while (used.count (x));
		// used.insert (x);
		printf("%c", x + 'a');
	}
	puts("");
}
