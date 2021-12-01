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
void input_graph()
{
    int n;
    cin >> n;
    int total_edges = 0;
    fo(i, n)
    {
        int num_edge = 0;
        cin >> num_edge;
        // graph[i].push_back(i + 1);
        int lol = num_edge;
        fo(j, num_edge)
        {
            int node;
            cin >> node;
            if (node < i + 1)
            {
                lol--;
            }
        }
        cout << lol << endl;
        total_edges += lol;
    }
    cout << n << " " << total_edges << endl;
    fo(i, n)
    {
        int num_edge = 0;
        cin >> num_edge;
        // graph[i].push_back(i + 1);
        fo(j, num_edge)
        {
            int node;
            cin >> node;
            if (node < i + 1)
            {
                cout << i + 1 << " " << node << endl;
            }
        }
    }
}
int main(void)
{
    input_graph();
    return 0;
}