void rotate (int x, int k) {
	int y=a[x].fa;
	if (~a[y].fa) a[a[y].fa].son[a[a[y].fa].son[1]==y]=x;
	a[x].fa=a[y].fa; a[y].son[k]=a[x].son[k^1];
	if (~a[x].son[k^1]) a[a[x].son[k^1]].fa=y;
	a[y].fa=x; a[x].son[k^1]=y;
	update(y); update(x); }
void splay(int x,int s=-1) {
	push_down(x);
	while (a[x].fa!=s) {
		int y=a[x].fa,z=a[y].fa;
		if (z==s) {
			push_down(z=y); push_down(x);
			rotate(x,a[y].son[1]==x);
		} else {
			push_down(z);push_down(y);push_down(x);
			int t1=a[y].son[1]==x,t2=a[z].son[1]==y;
			if (t1==t2)	rotate(y,t2),rotate(x,t1);
			else rotate(x,t1),rotate(x,t2); } } }
