/*	Fast power module : $\color{commentcolor}x^n$ */
int fpm (int x, int n, int mod) {
	int ans = 1, mul = x; while (n) {
		if (n & 1) ans = int (1ll * ans * mul % mod);
		mul = int (1ll * mul * mul % mod); n >>= 1; }
	return ans; }

