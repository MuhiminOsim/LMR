#define cl const line & 
struct line {
	point s, t;
	explicit line (cp s = point (), cp t = point ()) : s (s), t (t) {} };
bool point_on_segment (cp a, cl b) { return sgn (det (a - b.s, b.t - b.s)) == 0 && sgn (dot (b.s - a, b.t - a)) <= 0; }
bool two_side (cp a, cp b, cl c) { return sgn (det (a - c.s, c.t - c.s)) * sgn (det (b - c.s, c.t - c.s)) < 0; }
bool intersect_judgment (cl a, cl b) {
	if (point_on_segment (b.s, a) || point_on_segment (b.t, a)) return true;
	if (point_on_segment (a.s, b) || point_on_segment (a.t, b)) return true;
	return two_side (a.s, a.t, b) && two_side (b.s, b.t, a); }
point line_intersect (cl a, cl b) {
	double s1 = det (a.t - a.s, b.s - a.s), s2 = det (a.t - a.s, b.t - a.s);
	return (b.s * s2 - b.t * s1) / (s2 - s1); }
double point_to_line (cp a, cl b) { return fabs (det (b.t - b.s, a - b.s)) / dis (b.s, b.t); }
point project_to_line (cp a, cl b) { return b.s + (b.t - b.s) * (dot (a - b.s, b.t - b.s) / dis2 (b.t, b.s)); }
double point_to_segment (cp a, cl b) {
	if (sgn (dot (b.s - a, b.t - b.s) * dot (b.t - a, b.t - b.s)) <= 0) return fabs (det (b.t - b.s, a - b.s)) / dis (b.s, b.t);
	return std::min (dis (a, b.s), dis (a, b.t)); }
bool in_polygon (cp p, const std::vector <point> & po) {
	int n = (int) po.size (), counter = 0;
	for (int i = 0; i < n; ++i) {
		point a = po[i], b = po[(i + 1) % n];
		//Modify the next line if necessary.
		if (point_on_segment (p, line (a, b))) return true;
		int x = sgn (det (p - a, b - a)), y = sgn (a.y - p.y), z = sgn (b.y - p.y);
		if (x > 0 && y <= 0 && z > 0) counter++;
		if (x < 0 && z <= 0 && y > 0) counter--; }
	return counter != 0; }
double polygon_area (const std::vector <point> &a) {
	double ans = 0.0;
	for (int i = 0; i < (int) a.size (); ++i) ans += det (a[i], a[ (i + 1) % a.size ()]) / 2.0;
	return ans; }

