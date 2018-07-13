//Counter-clockwise, with minimum number of points.
bool turn_left (cp a, cp b, cp c) { return sgn (det (b - a, c - a)) >= 0; }
std::vector <point> convex_hull (std::vector <point> a) {
	int cnt = 0; std::sort (a.begin (), a.end ());
	std::vector <point> ret (a.size (), point ());
	for (int i = 0; i < (int) a.size (); ++i) {
		while (cnt > 1 && turn_left (ret[cnt - 2], a[i], ret[cnt - 1])) --cnt; 
		ret[cnt++] = a[i]; }
	int fixed = cnt;
	for (int i = (int) a.size () - 1; i >= 0; --i) {
		while (cnt > fixed && turn_left (ret[cnt - 2], a[i], ret[cnt - 1])) --cnt;
		ret[cnt++] = a[i]; }
	return std::vector (ret.begin (), ret.begin () + cnt - 1); }

