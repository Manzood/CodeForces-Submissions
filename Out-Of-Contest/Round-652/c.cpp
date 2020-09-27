#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

bool check(int a, int b) {
    if (a>b) return true;
    return false;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n,k;
        scanf("%d%d",&n,&k);
        vector <int> a(n);
        vector <int> b(k);
        for (int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        int ones=0;
        for (int i=0;i<k;i++) {
            scanf("%d",&b[i]);
            if (b[i]==1) {
                ones++;
            }
        }
        sort(a.begin(),a.end(),check);
        sort(b.begin(),b.end());
        long long ans=0;
        for (int i=0;i<k;i++) {
            ans+=a[i];
            // debug(a[i]);
        }
        for (int i=0;i<ones;i++) {
            ans+=a[i];
            // debug(a[i]);
        }
        int current=k-1;
        for (int i=0;i<k;i++) {
            current+=(b[i]-1);
            if (b[i]>1) {
                ans+=a[current];
                // debug(a[current]);
                // debug(current);
            }
        }
        cout<<ans<<endl;
    }
}
