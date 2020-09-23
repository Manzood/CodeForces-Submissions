#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define debug(x) cout<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		 int n;
		 scanf("%d\n",&n);
		 int c;
		 int first=0;
		 vector <int> a(n);
		 vector <int> b(n);
		 for (int i=0;i<n;i++) {
		 	c=getchar();
		 	c-='0';
		 	if (c==2) {
		 		if (first==0) {
		 			a[i]=1;
		 			b[i]=1;
		 		}
		 		else {
		 			a[i]=0;
		 			b[i]=2;
		 		}
		 	}
		 	else if (c==1) {
		 		if (first==0) {
		 			a[i]=1;
		 			b[i]=0;
		 			first=1;
		 		}
		 		else {
		 			a[i]=0;
		 			b[i]=1;
		 		}
		 	}
		 	else {
		 		a[i]=0;
		 		b[i]=0;
		 	}
		 }
		 for (int i=0;i<n;i++) {
		 	printf("%d",a[i]);
		 }
		 printf("\n");
		 for (int i=0;i<n;i++) {
		 	printf("%d",b[i]);
		 }
		 printf("\n");
	}
}