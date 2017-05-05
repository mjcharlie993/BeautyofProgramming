int Cal(int V, int T) {
    opt[0][T] = 0;
    for (int i = 1; i <= V; i++) {
        opt[i][T] = _INF;
    }
    for (int j = T - 1; j >= 0; j--) {
        for (int i = 0; i <= V; i++) {
            opt[i][j] = -INF;
            for (int k = 0; k <= C[j]; k++) {
                if (i < k * V[j]) {
                    break;
                }
                int x = opt[i - k * V[j]][j + 1];
                if (x != -INF) {
                    x += H[j] * k;
                    if (x > opt[i][j]) {
                        opt[i][j] = x;
                    }
                }
            }
        }
    }
    return opt[V][0];
}