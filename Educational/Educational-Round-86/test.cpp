#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>

using namespace std;

int main() {
	int count=0;
	for (int i=0;i<=2000;i++) {
		if ((i%119)%98==(i%98)%119) {
			printf("%d\n",i);
			count++;
		}
	}
	printf("%d\n",count);
}