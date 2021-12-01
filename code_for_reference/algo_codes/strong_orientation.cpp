#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define lightspeed ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define PI 3.14159265
#define br cout << endl
#define test_case while (t--)
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define f first
#define s second
#define pb push_back
#define file_read                       \
    freopen("Input.txt", "r", stdin);   \
    freopen("Output.txt", "w", stdout); \
    freopen("Error.txt", "w", stderr);
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int MOD = 1e9 + 7;

#define N 100000
vector<vector<pair<int, int>>> adj; // adjacency list - vertex and edge pairs
vector<pair<int, int>> edges;

vector<int> tin, low;
int bridge_cnt;
string orient;
vector<bool> edge_used;
void find_bridges(int v)
{
    static int time = 0;
    low[v] = tin[v] = time++;
    for (auto p : adj[v])
    {
        if (edge_used[p.second])
            continue;
        edge_used[p.second] = true;
        orient[p.second] = v == edges[p.second].first ? '>' : '<';
        int nv = p.first;
        if (tin[nv] == -1)
        { // if nv is not visited yet
            find_bridges(nv);
            low[v] = min(low[v], low[nv]);
            if (low[nv] > tin[v])
            {
                // a bridge between v and nv
                bridge_cnt++;
            }
        }
        else
        {
            low[v] = min(low[v], low[nv]);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    adj.resize(n);
    tin.resize(n, -1);
    low.resize(n, -1);
    orient.resize(m);
    edges.resize(m);
    edge_used.resize(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        edges[i] = {a, b};
    }
    int comp_cnt = 0;
    for (int v = 0; v < n; v++)
    {
        if (tin[v] == -1)
        {
            comp_cnt++;
            find_bridges(v);
        }
    }
    string s = orient.c_str();
    // cout << s << endl;

    printf("%d\n", comp_cnt + bridge_cnt);
    fo(i, m)
    {
        if (s[i] == '<')
            cout << edges[i].first + 1 << " " << s[i] << "-- " << edges[i].second + 1 << endl;
        else
            cout << edges[i].first + 1 << " --" << s[i] << " " << edges[i].second + 1 << endl;
    }
    return 0;
}
