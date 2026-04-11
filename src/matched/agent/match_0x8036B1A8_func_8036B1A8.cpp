// FLAGS: -fno-elide-constructors
extern int g1_8036B1A8[];
extern int g2_8036B1A8[];
extern int g3_8036B1A8[];
extern int g4_8036B1A8[];
extern int g5_8036B1A8[];
extern int g6_8036B1A8[];
extern void target_8036B1A8(void*, void*, void*, void*, void*, void*, void*);

void func_8036B1A8(void *self) {
    target_8036B1A8(g1_8036B1A8, g2_8036B1A8, g3_8036B1A8, g4_8036B1A8, self, g5_8036B1A8, g6_8036B1A8);
}
