#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n; cin>>n;
        string s;
        cin>>s;
        string res;
        bool found=false;
        int ones=0;
        bool zero=false;
        for (auto x: s) {
            if (x=='1' && found==false) {
                found=true;
                ones++;
            }
            else if (found==false) {
                res+=x;
            }
            else {
                if (x=='1') {
                    ones++;
                }
                else {
                    zero=true;
                    ones=0;
                }
            }
        }
        if (zero) res+='0';
        for (int i=0;i<ones;i++)
            res+='1';
        cout<<res<<endl;
    }
}
