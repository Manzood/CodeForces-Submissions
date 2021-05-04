#include <bits/stdc++.h>
using namespace std;

int N,L,R;
int C[200001];
int lcnt[200001],rcnt[200001];

void solve(){
  cin>>N>>L>>R;
  for (int i=1;i<=N;i++){
    lcnt[i]=0;
    rcnt[i]=0;
  }
  for (int i=1;i<=N;i++){
    cin>>C[i];
    if (i<=L)
      lcnt[C[i]]++;
    else
      rcnt[C[i]]++;
  }
  //remove pairs that are already matching
  for (int i=1;i<=N;i++){
    int mn=min(lcnt[i],rcnt[i]);
    lcnt[i]-=mn;
    rcnt[i]-=mn;
    L-=mn;
    R-=mn;
  }
  if (L<R){
    swap(lcnt,rcnt);
    swap(L,R);
  }
  //now, there are at least as many left socks as right socks
  int ans=0;
  for (int i=1;i<=N;i++){
    int extra=L-R; //always even
    int canDo=lcnt[i]/2;
    int Do=min(canDo*2,extra);
    //turn "Do"/2 left socks of color i into right socks
    ans+=Do/2;
    L-=Do;
  }
  //turn extra lefts into rights, then adjust all colors
  ans+=(L-R)/2+(L+R)/2;
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T; cin>>T;
  while (T--)
    solve();
  return 0;
}
