template <int MAXN = 100000, MAXM = 100000>
struct k_short {
	int f[MAXN], ff[MAXN];
	namespace left_tree{
		struct point { int l, r, h, v, x, y; } tr[MAXN * 40];
		int rt[MAXN], num;
		int alloc (point o) { tr[++num]=o; return num; }
		void start () { num = 0; tr[0].l = tr[0].r = tr[0].h = 0; tr[0].v = INF; }
		int mg(int x,int y){
			if(!x)return y;
			if(tr[x].v>tr[y].v)swap(x,y);
			int o=alloc(tr[x]);tr[o].r=mg(tr[o].r,y);
			if(tr[tr[o].l].h<tr[tr[o].r].h)swap(tr[o].l,tr[o].r);
			tr[o].h=tr[tr[o].r].h+1;return o;}
		void add(int&k,int v,int x,int y){
			int o=alloc(tr[0]);
			tr[o].v=v;tr[o].x=x;tr[o].y=y;
			k=mg(k,o);	}}
	using namespace left_tree;
	struct spfa{
		void in(){tot=0;CL(fir);}void ins(x,y,z){}
		void work(int S,int n){
	}}A;
	struct Kshort{
	int tot,n,m,S,T,k,fir[MAXN],va[M],la[M],ne[M];bool v[MAXN];
	struct point{
		int x,y,z;point(){}point(int x,int y,int z):x(x),y(y),z(z){}
		bool operator<(point a)const{return a.z<z;}};
	priority_queue<point>Q;void in(){tot=0;CL(fir);}
	void ins(x,y,z){}
	void init(){//将图读入
		int i,x,y,z;in();A.in();start();rd(n,m)
		fr(i,1,m)rd(x,y,z),A.ins(y,x,z),ins(x,y,z);
		rd(S,T,k);if(S==T)k++;//注意起点终点相同的情况
		A.work(T,n);}//A是反向边
	void dfs(int x){
		if(v[x])return;v[x]=1;if(f[x])rt[x]=rt[f[x]];
		for(int i=fir[x],y;i;i=ne[i])if(y=la[i],A.d[y]!=inf&&ff[x]!=i)
			add(rt[x],A.d[y]-A.d[x]+va[i],x,y);
		for(int i=A.fir[x];i;i=A.ne[i])if(f[A.la[i]]==x)dfs(A.la[i]);}
	int work(){//返回答案, 没有返回-1
		int i,x;dfs(T);
		if(!--k)return A.d[S]==inf?-1:A.d[S];
		point u,w;if(rt[S])Q.push(point(S,rt[S],A.d[S]+tr[rt[S]].v));
		for(;k--;){
			if(Q.empty())return -1;u=Q.top();Q.pop();
			if(x=mg(tr[u.y].l,tr[u.y].r))
				Q.push(point(u.x,x,tr[x].v-tr[u.y].v+u.z));
			if(rt[x=tr[u.y].y])Q.push(point(x,rt[x],u.z+tr[rt[x]].v));}
		return u.z;}}G;
