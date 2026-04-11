// FLAGS: -fno-elide-constructors
extern int g1_8036AC78[];
extern int g2_8036AC78[];
extern int g3_8036AC78[];
extern int g4_8036AC78[];
extern int g5_8036AC78[];
extern int g6_8036AC78[];
extern void target_8036AC78(void*, void*, void*, void*, void*, void*, void*);

void func_8036AC78(void *self) {
    target_8036AC78(g1_8036AC78, g2_8036AC78, g3_8036AC78, g4_8036AC78, self, g5_8036AC78, g6_8036AC78);
}
