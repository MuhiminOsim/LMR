long long mul_mod (long long x, long long y, long long mod) {
	long long t = (x * y - (long long) ((long double) x / mod * y + 1E-3) * mod) % mod;
	return t < 0 ? t + mod : t; }
