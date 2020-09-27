#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n, m, a;
	scanf("%d %d %d",&n,&m,&a);
	int ans1, ans2;
	ans1=n/a;
	if (n%a>0)
		ans1++;
	ans2=m/a;
	if (m%a>0)
		ans2++;
	//debug(ans1);
	//debug(ans2);
	printf("%lld",(long long)ans1*ans2);
}
