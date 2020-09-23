#include<bits/stdc++.h>
using namespace std;

int random(int a, int b) {
	return a + rand()%(b-a+1);
}

int main(int argc, char *argv[])
{
	srand(atoi(argv[1]));
	int n=random(1,1);
	printf("%d\n",n);
	for (int i=0;i<n;i++)
	{
		int a,b,q;
		a=random(1,200);
		b=random(1,200);
		q=random(1,20);
		printf("%d %d %d\n",a,b,q);
		for (int j=0;j<q;j++) {
			int l1,l2;
			l1=random(1,2000);
			l2=random(l1,2000);
			printf("%d %d\n",l1,l2);
		}
	}
	puts("");
}