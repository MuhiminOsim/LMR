#define cc const circle &
struct circle {
	point c; double r;
	explicit circle (point c = point (), double r = 0) : c (c), r (r) {} };
bool operator == (cc a, cc b) { return a.c == b.c && cmp (a.r, b.r) == 0; }
bool operator != (cc a, cc b) { return !(a == b); }
bool in_circle (cp a, cc b) { return cmp (dis (a, b.c), b.r) <= 0; }
circle make_circle (cp a, cp b) { return circle ((a + b) / 2, dis (a, b) / 2); }
circle make_circle (cp a, cp b, cp c) { point p = circumcenter (a, b, c); return circle (p, dis (p, a)); }
//In the order of the line vector.
std::vector <point> line_circle_intersect (cl a, cc b) {
	if (cmp (point_to_line (b.c, a), b.r) > 0) return std::vector <point> ();
	double x = sqrt (sqr (b.r) - sqr (point_to_line (b.c, a)));
	return std::vector <point> ({project_to_line (b.c, a) + (a.s - a.t).unit () * x, project_to_line (b.c, a) - (a.s - a.t).unit () * x}); }
double circle_intersect_area (cc a, cc b) {
	double d = dis (a.c, b.c);
	if (sgn (d - (a.r + b.r)) >= 0) return 0;
	if (sgn (d - abs(a.r - b.r)) <= 0) {
		double r = std::min (a.r, b.r); return r * r * PI; }
	double x = (d * d + a.r * a.r - b.r * b.r) / (2 * d), t1 = acos (min (1., max (-1., x / a.r))), t2 = acos (min (1., max (-1., (d - x) / b.r)));
	return a.r * a.r * t1 + b.r * b.r * t2 - d * a.r * sin (t1); }
//Counter-clockwise with respect of vector $\color{commentcolor}O_aO_b$.
std::vector <point> circle_intersect (cc a, cc b) {
	if (a.c == b.c || cmp (dis (a.c, b.c), a.r + b.r) > 0 || cmp (dis (a.c, b.c), std::abs (a.r - b.r)) < 0) return std::vector <point> ();
	point r = (b.c - a.c).unit ();
	double d = dis (a.c, b.c);
	double x = ((sqr (a.r) - sqr (b.r)) / d + d) / 2;
	double h = sqrt (sqr (a.r) - sqr (x));
	if (sgn (h) == 0) return std::vector <point> ({a.c + r * x});
	return std::vector <point> ({a.c + r * x - r.rot90 () * h, a.c + r * x + r.rot90 () * h}); }
//Counter-clockwise with respect of point $\color{commentcolor}a$.
std::vector <point> tangent (cp a, cc b) { circle p = make_circle (a, b.c); return circle_intersect (p, b); }
//Counter-clockwise with respect of point $\color{commentcolor}O_a$.
std::vector <line> extangent (cc a, cc b) {
	std::vector <line> ret;
	if (cmp (dis (a.c, b.c), std::abs (a.r - b.r)) <= 0) return ret;
	if (sgn (a.r - b.r) == 0) {
		point dir = b.c - a.c; dir = (dir * a.r / dis (dir)).rot90 ();
		ret.push_back (line (a.c - dir, b.c - dir));
		ret.push_back (line (a.c + dir, b.c + dir));
	} else {
		point p = (b.c * a.r - a.c * b.r) / (a.r - b.r); 
		std::vector pp = tangent (p, a), qq = tangent (p, b);
		if (pp.size () == 2 && qq.size () == 2) {
			if (cmp (a.r, b.r) < 0) std::swap (pp[0], pp[1]), std::swap (qq[0], qq[1]);
			ret.push_back (line (pp[0], qq[0]));
			ret.push_back (line (pp[1], qq[1])); } }
	return ret; }
//Counter-clockwise with respect of point $\color{commentcolor}O_a$.
std::vector <line> intangent (cc c1, cc c2) {
	point p = (b.c * a.r + a.c * b.r) / (a.r + b.r); 
	std::vector pp = tangent (p, a), qq = tangent (p, b);
	if (pp.size () == 2 && qq.size () == 2) {
		ret.push_back (line (pp[0], qq[0]));
		ret.push_back (line (pp[1], qq[1])); }
	return ret; }

