#include <bit/stdc++.h>

template <long long N = 2000000000000LL, int SN = 2000000, int D = 2>
struct ees {
	int co[SN + 1], prime[SN + 1], psize;
	long long powa[SN + 1], powb[SN + 1];
	ees () {
		for (int i = 2; i <= SN; ++i) {
			if (!co[i]) prime[psize++] = i;
			for (int j = 0; 1LL * i * prime[j] <= SN; ++j) {
				co[i * prime[j]] = 1;
				if (i % prime[j] == 0) break; } }
		for (int d = 0; d <= D; ++d) {
			for (int i = 1; i <= SN; ++i) powa[i] = pre_pow (i, d) - 1; 
			for (int i = 1; i <= SN; ++i) powb[i] = pre_pow (N / i, d) - 1;
			for (int i = 0; i < psize; ++i) { int &pi = prime[i];
				for (int j = 1; j <= SN; ++j) if (N / j >= pi * pi) {
					long long ch = N / j / pi;
					powb[j] -= ((ch <= SN ? powa[ch] : powb[j * pi]) - powa[pi - 1]) * pow (pi, d);
				} else break;
				for (int j = SN; j >= 1; --j) if (j >= pi * pi) {
			}
};

