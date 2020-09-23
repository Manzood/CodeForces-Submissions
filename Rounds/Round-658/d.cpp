#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        string a, goal;
        cin >> a >> goal;
        int left = 0;
        int right = n-1;
        int current = 0;
        bool toggle = true;
        vector <int> ans;
        int count = 0;
        int goalcounter = n-1;

        while (left <= right) {
            if (left == right) {
                if (count%2 == 0 && goal[0] != a[left]) 
                    ans.push_back(1);
                else if (count%2 == 1 && goal[0] == a[left]) 
                    ans.push_back(1);
                break;
            }
            char check;
            if (count % 2 == 0) 
                check = goal[goalcounter];
            else {
                if (goal[goalcounter] == '1') check = '0';
                else check = '1';
            }

            if (!toggle) {
                if (a[left] == check) {
                    left++;
                    goalcounter--;
                }
                else {
                    if (a[left] != a[right]) {
                        ans.push_back(1);
                        if (a[right] == '1') a[right] = '0';
                        else a[right] = '1';
                    }
                    else {
                        ans.push_back(right-left+1);
                        // debug(right-left+1);
                        right--;
                        count++;
                        goalcounter--;
                        toggle = true;
                    }
                }
            }
            else {
                if (a[right] == check) {
                    goalcounter--;
                    right--;
                }
                else {
                    if (a[left] != a[right]) {
                        ans.push_back(1);
                        if (a[left] == '1') a[left] = '0';
                        else a[left] = '1';
                    }
                    else {
                        ans.push_back(right-left+1);
                        left++;
                        goalcounter--;
                        toggle = false;
                        count++;
                    }
                }
            }
        }
        printf("%d ", (int) ans.size());
        for (int i=0; i<ans.size(); i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
}
