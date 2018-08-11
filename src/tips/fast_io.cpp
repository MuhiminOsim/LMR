#define __ __attribute__ ((optimize ("-O3"))) 
#define _ __ __inline __attribute__ ((__gnu_inline__, __always_inline__, __artificial__)) 

bool read_int (int &x) {
	const int SIZE = 1000000; static char buf[SIZE + 1]; static char *p = buf + SIZE;
	register int f = 0, sgn = 0; x = 0;
	while ((*p || (p = buf, buf[fread (buf, 1, SIZE, stdin)] = 0, buf[0])) && 
			(isdigit (*p) && (x = x * 10 + (*p - '0'), f = 1) || !f && (*p != '-' || (sgn = 1)))) ++p;
	if (sgn) x = -x;
	return buf[0]; }

void write (int f, const char *str, ...) {
	va_list args; va_start (args, str);
	const int SIZE = 1000000; static char buf[2 * SIZE], *p = buf;
	if ((p += vsprintf (p, str, args)) - buf >= SIZE || f) fwrite (buf, 1, p - buf, stdout), p = buf;
	va_end (args);
}

