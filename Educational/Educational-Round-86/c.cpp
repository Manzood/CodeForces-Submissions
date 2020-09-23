#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>

//I've just been fixing and overengineering the same convoluted shitty code.
//This is absolutely not the way to be approaching problems.
//Not only would I be unable to solve it in a contest, I'm unable to upsolve it properly
//Damn shame
//Anyhow, I'm gonna leave the problem for later, maybe I'll come back to it some day as a better programmer.
//I feel like I'm far too desperate for improvement, I should relax and enjoy the process rather than force myself to improve as fast as possible
//Upsolving is great, but only when it helps me think and improve
//This is just ridiculous, I'm following a crappy approach and overdoing terrible practises.
//I will come back to this another time, as a better programmer

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int getnearest(int temp, int product) {
	int x=temp;
	x+=(product-(x%product));
	if (temp-(x-product)<x-temp && x-product>=0)
		return (x-product);
	else return x;
}

int lcm(int a,int b) {
	return (a*b)/__gcd(a,b);
}

int main () {
	//find subset;
	//if it's a multiple of product, great
	//Otherwise check remainder
	int t;
	cin>>t;
	while (t--) {
		int a,b,q;
		int product;
		long long upper, lower;
		scanf("%d %d %d",&a,&b,&q);
		product=lcm(a,b);
		int base;
		long long ans=0;
		pair<int,int> bounds;
		for (int temp=0;temp<q;temp++) {
			ans=0;
			scanf("%lld %lld",&lower,&upper);
			bounds.first=getnearest(lower,product);
			if (bounds.first>lower)
				bounds.first-=product;
			bounds.second=getnearest(upper,product);
			if (bounds.second<upper)
				bounds.second+=product;
			int used=bounds.first;
			//debug(bounds.first);
			for (int i=lower;i<bounds.first+max(a,b) && i<=upper;i++) {
				ans++;
			}
			if (bounds.second==upper) {
				ans++;
			}
			bounds.first+=product;
			bounds.second-=product;
			for (int i=bounds.second;bounds.second!=used && i<=upper && i<bounds.second+max(a,b);i++) {
				ans++;
			}
			if (bounds.second>bounds.first)
				ans+=((bounds.second-bounds.first)/product)*max(a,b);
			//debug(ans);
			ans=upper-lower+1-ans;
			if (a==b) {
				ans=0;
			}
			if (ans<0)
				ans=0;
			printf("%lld ",ans);
		}
		printf("\n");
	}
}