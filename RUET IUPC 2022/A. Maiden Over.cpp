#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
  #include "dbg.h"    
#endif
#define  ll long long
#define  int ll
const int N = 1e6;

void solve () {
  int n; cin >> n;
  int p = 0;
  for (int i = 0; i < n; i++) {
    int tm = 0, a;
    for (int i = 0; i < 6; i++) {
      cin >> a;
      if(a == 0) tm++;
    }
    if(tm == 6) p++;
  }
  cout << p << endl;
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int tc, t = 0; 
  cin >> tc; while(tc --)
  {
    cout << "Case " << ++t << ": ";
    solve();
  }
             
}

