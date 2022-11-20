#include <bits/stdc++.h>
using namespace std;

#define  ll long long
#define  int ll
const int N = 1e6;

void solve () {
  int n, a; cin >> n;
  string x, y;
  map<string, string> par;
  map<string, int> Once_used;

  for (int i = 0; i < n; i++) {
    cin >> a;
    if(a == 1) {
      cin >> x >> y;
      if(par[x] == "") par[x] = x; // if x is first time used
      Once_used[x]++;
      if(par[y] != "") continue; //already in use

      par[y] = par[x];
      Once_used[y]++;
      par.erase(x);
    }
    else {
      cin >> x;
      if(Once_used[x]) {
        if(par[x] != "") cout << par[x] << '\n';
        else cout << "Not in use!\n";  //once used but replaced later
      }
      else {
        par[x] = x;   //first time in query
        Once_used[x]++;
        cout << x << '\n';
      }
    }
  }
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int tc; 
  cin >> tc; while(tc --)
             solve();
}

