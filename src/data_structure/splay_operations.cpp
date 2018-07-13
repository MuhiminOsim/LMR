void push_down (int x) {
	if (~n[x].c[0]) push (n[x].c[0], n[x].t);
	if (~n[x].c[1]) push (n[x].c[1], n[x].t);
	n[x].t = tag (); }
void update (int x) {
	n[x].m = gen (x);
	if (~n[x].c[0]) n[x].m = merge (n[n[x].c[0]].m, n[x].m);
	if (~n[x].c[1]) n[x].m = merge (n[x].m, n[n[x].c[1]].m); }
void rotate (int x, int k) {
	push_down (x); push_down (n[x].c[k]);
	int y = n[x].c[k]; n[x].c[k] = n[y].c[k ^ 1]; n[y].c[k ^ 1] = x;
	if (n[x].f != -1) n[n[x].f].c[n[n[x].f].c[1] == x] = y;
	n[y].f = n[x].f; n[x].f = y; if (~n[x].c[k]) n[n[x].c[k]].f = x; 
	update (x); update (y); }
void splay (int x, int s = -1) {
	push_down (x);
	while (n[x].f != s) {
		if (n[n[x].f].f != s) rotate (n[n[x].f].f, n[n[n[x].f].f].c[1] == n[x].f);
		rotate (n[x].f, n[n[x].f].c[1] == x); }
	update (x);
	if (s == -1) root = x; }
