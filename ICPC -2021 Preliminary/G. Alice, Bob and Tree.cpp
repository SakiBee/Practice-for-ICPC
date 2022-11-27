#include <bits/stdc++.h>
using namespace std;

#define  ll long long
const int N = 3e4+9;

vector<int> g[N];
bool color[N], vis[N];

void dfs(int n, int col) {
  color[n] = col;
  vis[n] = 1;
  for (auto u : g[n]) {
    if(!vis[u]) {
      dfs(u, col^1);
    }
  }
}


void solve () {
  int n; cin >> n;
  memset(vis, 0, sizeof(vis));
  memset(color, -1, sizeof(color));
  for (int i = 1; i <= n+5; i++) g[i].clear();

  vector<int>v(n+1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  int a, b;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 0);
  int Tot_Black = 0, Tot_white = 0, count_white = 0, count_black = 0;
  for (int i = 1; i <= n; i++) {
    if(color[i]) Tot_Black += v[i], count_black++;
    else Tot_white += v[i], count_white++;
  }
  ll mx = -1, ans = 0LL, temp_mx = 0;
  for (int i = 1; i <= n; i++) {
    if(color[i]) {
      temp_mx = 1LL * (v[i] * count_black) - Tot_Black;
      temp_mx -= ((1LL * v[i] * count_white) - Tot_white);
    }
    else {
      temp_mx = 1LL * (v[i] * count_white) - Tot_white;
      temp_mx -= ((1LL * v[i] * count_black) - Tot_Black);
    }

    if(temp_mx > mx) {
      mx = temp_mx;
      ans = i;
    }
  }
  cout << ans << endl;

}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int tc, t = 0; 
  cin >> tc; while(tc --) {
    cout << "Case " << ++t << ": ";
    solve();
  }
}

