// FLAGS: -fno-elide-constructors
extern int g1_80226F64[];
extern int g2_80226F64[];
extern int g3_80226F64[];
extern int g4_80226F64[];
extern int g5_80226F64[];
extern int g6_80226F64[];
extern void target_80226F64(void*, void*, void*, void*, void*, void*, void*);

void func_80226F64(void *self) {
    target_80226F64(g1_80226F64, g2_80226F64, g3_80226F64, g4_80226F64, self, g5_80226F64, g6_80226F64);
}
