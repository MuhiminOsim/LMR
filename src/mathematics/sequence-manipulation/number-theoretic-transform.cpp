template <int MAXN = 1000000, int LOGN = 20>
struct ntt {
	int MOD[3] = {1045430273, 1051721729, 1053818881}, PRT[3] = {3, 6, 7};
	int exp[LOGN][MAXN][2];
	int init (int n, int mod = 998244353, int prt = 3) {
		int len = 1; for (; len <= 2 * n; len <<= 1);
		for (int i = 2, cnt = 0; i <= n; i <<= 1, ++cnt) {
			exp[cnt][0][0] = exp[cnt][0][1] = 1; exp[cnt][1][0] = fpm (prt, (mod - 1) / i, mod);
			exp[cnt][1][1] = fpm (exp[cnt][1][0], mod - 2, mod);
			for (int k = 2; k < (i >> 1); ++k) for (int t = 0; t < 2; ++t)
				exp[cnt][k][t] = int (1ll * exp[cnt][k - 1][t] * exp[cnt][1][t] % mod); }
		return len; }
	void solve (int *a, int n, int f = 0) {
		for (int i = 0, j = 0; i < n; ++i) {
			if (i > j) std::swap (a[i], a[j]);
			for (int t = n >> 1; (j ^= t) < t; t >>= 1); }
		for (int i = 2, cnt = 0; i <= n; i <<= 1, ++cnt)
			for (int j = 0; j < n; j += i) for (int k = 0; k < (i >> 1); ++k) {
				int &pA = a[j + k], &pB = a[j + k + (i >> 1)];
				int A = pA, B = int (1ll * pB * exp[cnt][k][f] % mod);
				pA = A + B < mod ? A + B : A + B - mod;
				pB = A - B >= 0 ? A - B : A - B + mod; }
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
