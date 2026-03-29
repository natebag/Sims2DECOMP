struct C { char p[0x80]; int m; int f(); };
int C::f() { return m; }
