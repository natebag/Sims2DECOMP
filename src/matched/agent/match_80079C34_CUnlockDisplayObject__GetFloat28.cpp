struct C { char p[0x28]; float m; float f(); };
float C::f() { return m; }
