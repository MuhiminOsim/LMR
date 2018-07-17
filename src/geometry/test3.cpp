#include <bits/stdc++.h>
#define cd const double &
const double EPS = 1E-8, PI = acos (-1);
int sgn (cd x) { return x < -EPS ? -1 : x > EPS; }
int cmp (cd x, cd y) { return sgn (x - y); }
double sqr (cd x) { return x * x; }
#define cp3 const point3 &
struct point3 {
	double x, y, z;
	explicit point3 (cd x = 0, cd y = 0, cd z = 0) : x (x), y (y), z (z) {} };
point3 operator + (cp3 a, cp3 b) { return point3 (a.x + b.x, a.y + b.y, a.z + b.z); }
point3 operator - (cp3 a, cp3 b) { return point3 (a.x - b.x, a.y - b.y, a.z - b.z); }
point3 operator * (cp3 a, cd b) { return point3 (a.x * b, a.y * b, a.z * b); }
point3 operator / (cp3 a, cd b) { return point3 (a.x / b, a.y / b, a.z / b); }
double dot (cp3 a, cp3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
point3 det (cp3 a, cp3 b) { return point3 (a.y * b.z - a.z * b.y, -a.x * b.z + a.z * b.x, a.x * b.y - a.y * b.x); }
double dis2 (cp3 a, cp3 b = point3 ()) { return sqr (a.x - b.x) + sqr (a.y - b.y) + sqr (a.z - b.z); }
double dis (cp3 a, cp3 b = point3 ()) { return sqrt (dis2 (a, b)); }
//right-handed, if x+ -> y+ is right-handed
point3 rotate(cp3 p, cp3 axis, double w) {
	double x = axis.x, y = axis.y, z = axis.z;
	double s = x * x + y * y + z * z, ss = sqrt(s), cosw = cos(w), sinw = sin(w);
	double a[4][4]; memset(a, 0, sizeof (a));
	a[3][3] = 1;
	a[0][0] = ((y * y + z * z) * cosw + x * x) / s;
	a[0][1] = x * y * (1 - cosw) / s + z * sinw / ss;
	a[0][2] = x * z * (1 - cosw) / s - y * sinw / ss;
	a[1][0] = x * y * (1 - cosw) / s - z * sinw / ss;
	a[1][1] = ((x * x + z * z) * cosw + y * y) / s;
	a[1][2] = y * z * (1 - cosw) / s + x * sinw / ss;
	a[2][0] = x * z * (1 - cosw) / s + y * sinw / ss;
	a[2][1] = y * z * (1 - cosw) / s - x * sinw / ss;
	a[2][2] = ((x * x + y * y) * cos(w) + z * z) / s;
	double ans[4] = {0, 0, 0, 0}, c[4] = {p.x, p.y, p.z, 1};
	for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j)
		ans[i] += a[j][i] * c[j];
	return point3 (ans[0], ans[1], ans[2]);
}
#define cl3 const line3 &
struct line3 {
	point3 s, t;
	explicit line3 (cp3 s = point3 (), cp3 t = point3 ()) : s (s), t (t) {} };
point3 line_plane_intersection (cl3 a, cl3 b) { return a.s + (a.t - a.s) * dot (b.s - a.s, b.t - b.s) / dot (a.t - a.s, b.t - b.s); }
line3 plane_intersection (cl3 a, cl3 b) {
	point3 p = det (a.t - a.s, b.t - b.s), q = det (a.t - a.s, p), s = line_plane_intersection (line3 (a.s, a.s + q), b);
	return line3 (s, s + p); }
point3 project_to_plane (cp3 a, cl3 b) { return a + (b.t - b.s) * dot (b.t - b.s, b.s - a) / dis2 (b.t - b.s); }

