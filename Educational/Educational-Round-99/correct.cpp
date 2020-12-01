/**
 * Dont raise your voice, improve your argument.
 * --Desmond Tutu
 */
 
#include <bits/stdc++.h>
using namespace std;
 
const bool ready = [](){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(12);
    return true;
}();
 
using ld=long double;
const ld PI = acos(-1);
using ll= long long;
#define int ll
#define all(v) (v).begin(), (v).end()
#define fori(n) for(int i=0; i<int(n); i++)
 
#define cini(i) int i; cin>>i;
#define cins(s) string s; cin>>s;
#define cind(d) ld d; cin>>d;
#define cinai(a,n) vi a(n); fori(n) { cin>>a[i]; }
#define cinas(s,n) vs s(n); fori(n) { cin>>s[i]; }
#define cinad(a,n) vd a(n); fori(n) { cin>>a[i]; }
 
using pii= pair<int, int>;
using pdd= pair<ld, ld>;
using vd= vector<ld>;
using vb= vector<bool>;
using vi= vector<int>;
using vvi= vector<vi>;
using vs= vector<string>;
 
#define endl "\n"
 
/* x increases, since we can swap x only if a[i]>x
 * Consider x and the position we must put it.
 * We cannot put it where a[i]<=x, ans we must put it
 * at the first a[i]>x, since if we put it later
 * then the array is not sorted.
 *
 * Since we can replace numbers by smaller numbers, 
 * we must replace a[i] if a[i]>a[i+1].
 * Simply to that from left to right.
 * Then Check if 
 *
 * How to profe the minimal number of swaps?
 * Is it dp somehow? What is the state?
 */
void solve() {
    cini(n);
    cini(x);
    cinai(a,n);
 
    bool sorted=true;
    for(int i=0; i+1<n; i++) 
        if(a[i]>a[i+1])
            sorted=false;
 
    if(sorted) {
        cout<<0<<endl;
        return;
    }
 
    int spos=n-1;   /* position until sorted from right end */
    for(; spos>0 && a[spos]>=a[spos-1]; spos--)
        ;
 
    int prev=-1;
    bool ok=true;
    int ans=0;
 
    for(int i=0; i<n; i++) {
        if(a[i]>x) {
           if(x>=prev) {
                swap(a[i],x);
                ans++;
           } else
               ok=false;
        } else if(i>=spos && a[i]>=prev)
            break;
 
        if(a[i]<prev)
            ok=false;
 
        prev=a[i];
    }
 
    if(!ok)
        ans=-1;
 
    cout<<ans<<endl;
}
 
signed main() {
    cini(t);
    while(t--)
        solve();
}
 
// FIRST THINK, THEN CODE
// DO NOT JUMP BETWEEN PROBLEMS