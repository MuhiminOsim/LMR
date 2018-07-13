/* Number theoretic transform : NTT for any module. 
Usage : Perform NTT on 3 modules and call crt () to merge the result. */
template <int MAXN = 1000000>
struct ntt {
	int MOD[3] = {1045430273, 1051721729, 1053818881}, PRT[3] = {3, 6, 7};
	void solve (int *a, int n, int f, int mod, int prt) {
		for (int i = 0, j = 0; i < n; ++i) {
			if (i > j) std::swap (a[i], a[j]);
			for (int t = n >> 1; (j ^= t) < t; t >>= 1); }
		for (int i = 2; i <= n; i <<= 1) {
			static int exp[MAXN]; exp[0] = 1;
			exp[1] = fpm (prt, (mod - 1) / i, mod);
			if (f == 1) exp[1] = fpm (exp[1], mod - 2, mod);
			for (int k = 2; k < (i >> 1); ++k) {
				exp[k] = int (1ll * exp[k - 1] * exp[1] % mod); }
			for (int j = 0; j < n; j += i) {
				for (int k = 0; k < (i >> 1); ++k) {
					int &pA = a[j + k], &pB = a[j + k + (i >> 1)];
					int A = pA, B = int (1ll * pB * exp[k] % mod);
					pA = (A + B) % mod;
					pB = (A - B + mod) % mod; } } }
		if (f == 1) {
			int rev = fpm (n, mod - 2, mod);
			for (int i = 0; i < n; ++i) a[i] = int (1ll * a[i] * rev % mod); } }
	int crt (int *a, int mod) {
		static int inv[3][3];
		for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j)
			inv[i][j] = (int) inverse (MOD[i], MOD[j]);
		static int x[3];
		for (int i = 0; i < 3; ++i) { x[i] = a[i];
			for (int j = 0; j < i; ++j) {
				int t = (x[i] - x[j] + MOD[i]) % MOD[i];
				if (t < 0) t += MOD[i];
				x[i] = int (1LL * t * inv[j][i] % MOD[i]); } }
		int sum = 1, ret = x[0] % mod;
		for (int i = 1; i < 3; ++i) {
			sum = int (1LL * sum * MOD[i - 1] % mod);
			ret += int (1LL * x[i] * sum % mod);
			if (ret >= mod) ret -= mod; }
		return ret; } };

