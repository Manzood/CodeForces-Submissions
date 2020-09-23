#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long

int32_t main() {
	long long a, b, c;
	cin>>a>>b>>c;
	cout<<"First"<<endl;
	int inp;
	int m = max(max(a,b),c);
	int mi = min(min(a,b),c);
	int second = (a+b+c) - (m+mi);
	int y;
	y = 2*m - mi - second;
	cout<<y<<endl;
	cin>>inp;
	int temp[3];
	temp[0]=a;
	temp[1]=b;
	temp[2]=c;
	bool maxchosen=false;
	while (inp!=0 && inp!=-1) {
		if (inp == 1) a+=y;
		else if (inp == 2) b+=y;
		else if (inp == 3) c+=y;
		if (temp[inp-1]==m) {
			maxchosen=true;
		}
		// debug(maxchosen);
		// debug(a);
		// debug(b);
		// debug(c);
		int m = max(max(a,b),c);
		int mi = min(min(a,b),c);
		int second = (a+b+c) - (m+mi);
		if (maxchosen) {
			y = 2*m - mi - second;
			maxchosen=false;
		}
		else {
			y=second-mi;
		}
		cout<<y<<endl;
		cin>>inp;
	}
}