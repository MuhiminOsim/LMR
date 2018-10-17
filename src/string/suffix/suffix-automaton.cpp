template <int MAXN = 1000000, int MAXC = 26>
struct suffix_automaton {
	struct state {
		int len, first, cnt; state *parent, *go[MAXC];
		state (int len = 0, int first = 0, int cnt = 0) : len (len), first (first), cnt (cnt), parent (0) {
			std::fill (go, go + MAXC, 0); } } node_pool[MAXN * 2], *tot_node, *start, *null;
	state *extend (state *tail, int token) {
		state *p = tail; state *np = tail -> go[token] ? null : new (*tot_node++) state (tail -> len + 1, tail -> len, 1);
		while (p && !p -> go[token]) p -> go[token] = np, p = p -> parent;
		if (!p) np -> parent = start;
		else {
			state *q = p -> go[token];
			if (p -> len + 1 == q -> len) {
				np -> parent = q; } else {
				state *nq = new (tot_node++) state (*q); nq -> cnt = 0;
				nq -> len = p -> len + 1; np -> parent = q -> parent = nq;
				while (p && p -> go[token] == q) {
					p -> go[token] = nq, p = p -> parent; } } }
		return np == null ? np -> parent : np; }
	void calc_cnt () {
		static state *list[MAXN * 2]; state **end = list;
		for (state *it = node_pool; it != tot_node; *(end++) = it++);
		std::sort (list, end, [&] (state *a, state *b) { return a -> len > b -> len; });
		for (state **it = list, it != end; ++it) (*it) -> parent -> cnt += (*it) -> cnt; }
	void init () {
		tot_node = node_pool; start = new (tot_node++) state (); null = new state (); }
	suffix_automaton () { init (); } };
