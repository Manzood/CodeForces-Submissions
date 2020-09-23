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
		// for quick reversal, use a jumping counter
		int acounter=0;
		while (i>=0) {
			// if (goal[i] != a[i] && goal[i] != a[0]) {
			// replace goal[i] with a check, to account for flips
			// if (acounter > i) acounter = i;
			char check;
			if (count%2 != 0) {
				if (goal[i] == '0') check = '1';
				else check = '0';
			}
			else {
				check = goal[i];
			}
			int ind;
			if (count%2 == 0) {
				ind = acounter+i;
			}
			else ind = acounter-i;

			if (check != a[ind] && check != a[acounter]) {
				count++;
				// if (i+1 == 2) {
					// debug(check);
					// debug(acounter-i);
				// }
				if (count%2==1) {
					acounter=ind;
				}
				else acounter = i;
				ans.push_back(i+1);
				i--;
			}
			else if (check != a[ind]) {
				ans.push_back(1);
				if (a[acounter] == '1') a[acounter] = '0';
				else a[acounter] = '1';	
				// debug(i);
			}
			if (acounter > 0) ind = acounter-i;
			else ind = i;
			if (check == a[ind]) {
				i--;
			}
		}
		// debug(goal);	
		ans.push_back(n);
		printf("%d ", (int)ans.size());
		for (int j=0; j<ans.size(); j++) {
			printf("%d ", ans[j]);
		}
		printf("\n");
	}
}