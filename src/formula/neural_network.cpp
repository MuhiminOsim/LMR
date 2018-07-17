/*	Neural network : machine learning. */
template <int ft = 6, int n = 6, int MAXDATA = 100000>
struct network {
	double wp[n][ft], w[n], avg[ft + 1], sig[ft + 1], val[n];
	network () {
		std::mt19937_64 mt (time (0));
		std::uniform_real_distribution <double> urdp (0, 2 * sqrt (ft));
		std::uniform_real_distribution <double> urdn (0, 2 * sqrt (n));
		for (int i = 0; i < n; ++i) for (int j = 0; j < ft; ++j) wp[i][j] = urdp (mt);
		for (int i = 0; i < n; ++i) w[i] = urdn (mt);
		for (int i = 0; i < ft + 1; ++i) avg[i] = sig[i] = 0; }
	double compute (double *x) {
		for (int i = 0; i < n; ++i) {
			val[i] = 0; for (int j = 0; j < ft; ++j) val[i] += wp[i][j] * x[j];
			val[i] = 1 / (1 + exp (-val[i])); }
		double res = 0; for (int i = 0; i < n; ++i) res += val[i] * w[i];
//		return 1 / (1 + exp (-res));
		return res; }
	void desc (double *x, double t, double eta) {
		double o = compute (x), del = (o - t); // * o * (1 - o)
		for (int i = 0; i < n; ++i) for (int j = 0; j < ft; ++j)
			wp[i][j] -= eta * del * val[i] * (1 - val[i]) * w[i] * x[j];
//		for (int i = 0; i < ft; ++i) w[i] -= eta * del * o * (1 - o) * val[i];
		for (int i = 0; i < n; ++i) w[i] -= eta * del * val[i]; } 
	void train (double data[MAXDATA][ft + 1], int dn, int epoch, double eta) {
		for (int i = 0; i < ft + 1; ++i) for (int j = 0; j < dn; ++j) avg[i] += data[j][i];
		for (int i = 0; i < ft + 1; ++i) avg[i] /= dn; 
		for (int i = 0; i < ft + 1; ++i) for (int j = 0; j < dn; ++j)
			sig[i] += (data[j][i] - avg[i]) * (data[j][i] - avg[i]);
		for (int i = 0; i < ft + 1; ++i) sig[i] = sqrt (sig[i] / dn); 
		for (int i = 0; i < ft + 1; ++i) for (int j = 0; j < dn; ++j)
			data[j][i] = (data[j][i] - avg[i]) / sig[i];
		for (int cnt = 0; cnt < epoch; ++cnt) for (int test = 0; test < dn; ++test)
			desc (data[test], data[test][ft], eta); }
	double predict (double *x) {
		for (int i = 0; i < ft; ++i) x[i] = (x[i] - avg[i]) / sig[i];
		return compute (x) * sig[ft] + avg[ft]; }
	std::string to_string () {
		std::ostringstream os; os.precision (20); os << std::fixed;
		for (int i = 0; i < n; ++i) for (int j = 0; j < ft; ++j) os << wp[i][j] << " ";
		for (int i = 0; i < n; ++i) os << w[i] << " ";
		for (int i = 0; i < ft + 1; ++i) os << avg[i] << " ";
		for (int i = 0; i < ft + 1; ++i) os << sig[i] << " ";
		return os.str (); }
	void read (const std::string &str) {
		std::istringstream is (str);
		for (int i = 0; i < n; ++i) for (int j = 0; j < ft; ++j) is >> wp[i][j];
		for (int i = 0; i < n; ++i) is >> w[i];
		for (int i = 0; i < ft + 1; ++i) is >> avg[i];
		for (int i = 0; i < ft + 1; ++i) is >> sig[i]; } };

