#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> adj;
vector<int> Pair_U, Pair_V, Dist;
const int NIL = 0, INF = INT_MAX;

//Is Correct
bool bfs(int k)
{
    queue<int> Q;

    for(int i=1; i<=n; i++)
    {
        if(Pair_U[i] == NIL)
        {
            Dist[i] = 0;
            Q.push(i);
        }
        else Dist[i] = INF;
    }
    Dist[NIL] = INF;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        if(Dist[u] < Dist[NIL])
        {
            for(pair<int, int> c: adj[u])
            {
                int v = c.first, p = c.second;
                if(p <= k && Dist[Pair_V[v]] == INF)
                {
                    Dist[Pair_V[v]] = Dist[u] + 1;
                    Q.push(Pair_V[v]);
                }
            }
        }
    }

    return Dist[NIL] != INF;
}

//Is Correct
bool dfs(int u, int k)
{
    if(u != NIL)
    {
        for(pair<int, int> c: adj[u])
        {
            int v = c.first, p = c.second;
            if(p <= k && Dist[Pair_V[v]] == Dist[u] + 1)
            {
                if(dfs(Pair_V[v], k))
                {
                    Pair_V[v] = u;
                    Pair_U[u] = v;
                    return true;
                }
            }
        }
        Dist[u] = INF;
        return false;
    }
    return true;
}

//Is Correct
//Modified Hopcroft - Karp (See Ed Discussion for more info)
int HK(int k)
{
    int cnt = 0;

    Pair_U = vector<int>(n+1, NIL);
    Pair_V = vector<int>(n+1, NIL);
    Dist = vector<int>(n+1);

    while(bfs(k))
    {
        for(int i=1; i<=n; i++)
        {
            if(Pair_U[i] == NIL && dfs(i, k)) cnt++;
        }
    }

        
    printf("%d\n", cnt);
    for(int i=1; i<=n; i++)
    {
        if(Pair_U[i] != NIL){
            printf("%d %d\n", i, Pair_U[i]);
        }
    }
    return n;
}

int main()
{ 

    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    scanf("%d %d %d\n", &n, &m, &k);
    
    adj = vector<vector<pair<int, int>>>(n+1);
    vector<vector<int>> edge(m);
    for(int i=0; i<k; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[i] = {u, v};
    }
    //sort(edge.begin(), edge.end());

    for(int i=0; i<k; i++)
    {
        int u = edge[i][1], v = edge[i][2];
        adj[u].pb({v, i});
    }

    HK(k);
}

