struct C { char p[0x4]; int m; int f(); };
int C::f() { return m; }
