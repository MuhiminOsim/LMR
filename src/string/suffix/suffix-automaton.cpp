template <int MAXN = 1000000, int MAXC = 26>
struct suffix_automaton {
	struct state {
		int len, right; state *parent, *dest[MAXC];
		state (int len = 0, int right = 0) : len (len), right (right), parent (NULL) {
			memset (dest, 0, sizeof (dest)); }
	} node_pool[MAXN * 2], *tot_node, *null = new state();
	state *head, *tail;
	void extend (int token) {
		state *p = tail;
		state *np = tail -> dest[token] ? null : new (tot_node++) state (tail -> len + 1, tail -> len + 1);
		while (p && !p -> dest[token]) p -> dest[token] = np, p = p -> parent;
		if (!p) np -> parent = head;
		else {
			state *q = p -> dest[token];
			if (p -> len + 1 == q -> len) {
				np -> parent = q;
			} else {
				state *nq = new (tot_node++) state (*q);
				nq -> len = p -> len + 1;
				np -> parent = q -> parent = nq;
				while (p && p -> dest[token] == q) {
					p -> dest[token] = nq, p = p -> parent;
				} } }
		tail = np == null ? np -> parent : np; }
	void init () {
		tot_node = node_pool;
		head = tail = new (tot_node++) state (); }
	suffix_automaton () { init (); } };

