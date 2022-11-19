#include <bits/stdc++.h>
using namespace std;
// #ifndef ONLINE_JUDGE
//   #include "dbg.h"    
// #endif
const int N = 1e6+5;
vector<int> parent(N), sz(N), mp(N);
int n;

void make_set(int v) {
  parent[v] = v;
  sz[v] = 1;
}
int find_set(int v) {
  if(v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if(a != b) {
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int tc = 1, t = 0; 
  cin >> tc;
  while(tc--) {
    cin >> n;
    if(mp[n]) {
      cout<< "Case " << ++t << ": " << mp[n] << '\n';
      continue;
    }
    for (int i = 1; i <= n; i++) make_set(i);
    int u, v, w, cost = 0;

    for (int i = n; i > 0; i--) {
      for (int j = i; j <= n; j += i) {
        w = i; u = i; v = j;
        int p = find_set(u), q = find_set(v);
        if(p != q) {
          cost += w;
          union_set(u, v);
        }
      }
    }
    cout << "Case " << ++t << ": " << cost << '\n';
    mp[n] = cost;
  }
}

