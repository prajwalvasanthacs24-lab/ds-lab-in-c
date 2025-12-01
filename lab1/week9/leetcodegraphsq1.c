bool dfs(int u, int destination, bool* vis, int** adj, int* adjSize) {
    if (u == destination) return true;
    vis[u] = true;
    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            if (dfs(v, destination, vis, adj, adjSize)) {
                return true;
            }
        }
    }
    return false;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize,
               int source, int destination) {
    if (source == destination) return true;

    int* adjSize = calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    int** adj = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = malloc(adjSize[i] * sizeof(int));
    }

    int* index = calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][index[u]++] = v;
        adj[v][index[v]++] = u;
    }

    bool* vis = calloc(n, sizeof(bool));
    bool result = dfs(source, destination, vis, adj, adjSize);

    free(vis);
    free(index);
    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(adjSize);

    return result;
}
