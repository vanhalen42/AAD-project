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
int n;                   // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
void IS_BRIDGE(int v, int to)
{
    cout << "Bridge: " << v + 1 << " -> " << to + 1 << endl;
}
void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}
vvi input_graph()
{
    // int n;
    cin >> n;
    vvi graph(n);
    fo(i, n)
    {
        int num_edge = 0;
        cin >> num_edge;
        // graph[i].push_back(i + 1);
        fo(j, num_edge)
        {
            int node;
            cin >> node;
            graph[i].push_back(node - 1);
        }
    }
    return graph;
}
void find_bridges()
{
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}
int main(void)
{
    adj = input_graph();
    // fo(i, adj.size())
    // {
    //     fo(j, adj[i].size())
    //             cout
    //         << adj[i][j] << " ";
    //     cout << endl;
    // }
    find_bridges();
    return 0;
}