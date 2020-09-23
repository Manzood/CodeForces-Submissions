#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
 
int main() {
	// store the opposite of b, then do a massive flip at the end
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		string a, b;
		cin >> a >> b;
		string goal;
		for (int i=n-1; i>=0; i--) {
			if (b[i] == '0') goal += "1";
			if (b[i] == '1') goal += "0";
		}
		vector <int> ans;
		int count = 0;
		int i=n-1;
		// debug(goal);
		while (i>=0) {
			// debug(i);
			if (goal[i] != a[i] && goal[i] != a[0]) {
				count++;
				reverse(a.begin(), a.begin()+i+1);
				for (int j=0; j<=i; j++) {
					if (a[j] == '1') a[j] = '0';
					else a[j] = '1';
				}
				ans.push_back(i+1);
				i--;
			}
			else if (goal[i] != a[i]) {
				ans.push_back(1);
				if (a[0] == '1') a[0] = '0';
				else a[0] = '1';	
			}
			if (goal[i] == a[i]) i--;
			// debug(a);
			// debug(i);
		}
		ans.push_back(n);
		printf("%d ", (int)ans.size());
		for (int j=0; j<ans.size(); j++) {
			printf("%d ", ans[j]);
		}
		printf("\n");
	}
}
