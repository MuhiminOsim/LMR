template <int MAXN = 1000000, int MAXM = 1000000>
struct tarjan {
	int comp[MAXN], size;
	int dfn[MAXN], ind, low[MAXN], ins[MAXN], stk[MAXN], stks;
	void dfs (const edge_list <MAXN, MAXM> &e, int i) {
		dfn[i] = low[i] = ind++;
		ins[i] = 1; stk[stks++] = i;
		for (int x = e.begin[i]; ~x; x = e.next[x]) {
			int j = e.dest[x]; if (!~dfn[j]) {
				dfs (e, j);
				if (low[i] > low[j]) low[i] = low[j];
				if (low[j] > dfn[i]);	//edge-biconnected
				if (low[j] >= dfn[i]);	//vertex-biconnected
			} else if (ins[j] && low[i] > dfn[j])
				low[i] = dfn[j]; }
		if (dfn[i] == low[i]) {			//strongly-connected
			for (int j = -1; j != i;
				j = stk[--stks], ins[j] = 0, comp[j] = size);
			++size; } }
	void solve (const edge_list <MAXN, MAXM> &e, int n) {
		size = ind = stks = 0;
		std::fill (dfn, dfn + n, -1);
		for (int i = 0; i < n; ++i) if (!~dfn[i])
			dfs (e, i); } };

