/*	Berlekamp Massey algorithm : Complexity: O(n^2) Requirement: const MOD, inverse(int)
Input: the first elements of the sequence
Output: the recursive equation of the given sequence
Example In: {1, 1, 2, 3}
Example Out: {1, 1000000006, 1000000006} (MOD = 1e9+7) */
struct berlekamp-massey {
	struct Poly { std::vector <int> a; Poly() { a.clear(); }
		Poly (std::vector <int> &a) : a (a) {}
		int length () const { return a.size(); }
		Poly move (int d) { std::vector <int> na (d, 0);
			na.insert (na.end (), a.begin (), a.end ());
			return Poly (na); }
		int calc(std::vector <int> &d, int pos) { int ret = 0;
			for (int i = 0; i < (int) a.size (); ++i) {
				if ((ret += 1LL * d[pos - i] * a[i] % MOD) >= MOD) {
					ret -= MOD; } }
			return ret; }
		Poly operator - (const Poly &b) {
			std::vector <int> na (std::max (this -> length (), b.length ()));
			for (int i = 0; i < (int) na.size (); ++i) {
				int aa = i < this -> length () ? this -> a[i] : 0,
					bb = i < b.length () ? b.a[i] : 0;
				na[i] = (aa + MOD - bb) % MOD; }
			return Poly (na); } };
	Poly operator * (const int &c, const Poly &p) {
		std::vector <int> na (p.length ());
		for (int i = 0; i < (int) na.size (); ++i) {
			na[i] = 1LL * c * p.a[i] % MOD; }
		return na; }
	std::vector <int> solve(vector<int> a) {
		int n = a.size (); Poly s, b;
		s.a.push_back (1), b.a.push_back (1);
		for (int i = 0, j = -1, ld = 1; i < n; ++i) {
			int d = s.calc(a, i); if (d) {
				if ((s.length () - 1) * 2 <= i) {
					Poly ob = b; b = s;
					s = s - 1LL * d * inverse (ld) % MOD * ob.move (i - j);
					j = i; ld = d;
				} else {
					s = s - 1LL * d * inverse (ld) % MOD * b.move (i - j); } } }
		return s.a; } };

