#define cp const point &
struct point {
	double x, y;
	explicit point (cd x = 0, cd y = 0) : x (x), y (y) {}
	int dim () const { return sgn (y) == 0 ? sgn (x) > 0 : sgn (y) > 0; }
	point unit () const { double l = msqrt (x * x + y * y); return point (x / l, y / l); }
	point rot90 () const { return point (-y, x); }
	point _rot90 () const { return point (y, -x); }
	point rot (cd t) const {
		double c = cos (t), s = sin (t);
		return point (x * c - y * s, x * s + y * c); } };
bool operator == (cp a, cp b) { return cmp (a.x, b.x) == 0 && cmp (a.y, b.y) == 0; }
bool operator != (cp a, cp b) { return cmp (a.x, b.x) != 0 || cmp (a.y, b.y) != 0; }
bool operator < (cp a, cp b) { return cmp (a.x, b.x) == 0 ? cmp (a.y, b.y) < 0 : cmp (a.x, b.x) < 0; }
point operator - (cp a) { return point (-a.x, -a.y); }
point operator + (cp a, cp b) { return point (a.x + b.x, a.y + b.y); }
point operator - (cp a, cp b) { return point (a.x - b.x, a.y - b.y); }
point operator * (cp a, cd b) { return point (a.x * b, a.y * b); }
point operator / (cp a, cd b) { return point (a.x / b, a.y / b); }
double dot (cp a, cp b) { return a.x * b.x + a.y * b.y; }
double det (cp a, cp b) { return a.x * b.y - a.y * b.x; }
double dis2 (cp a, cp b = point ()) { return sqr (a.x - b.x) + sqr (a.y - b.y); }
double dis (cp a, cp b = point ()) { return msqrt (dis2 (a, b)); }

