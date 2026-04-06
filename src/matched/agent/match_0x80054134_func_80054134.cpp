// FLAGS: -fno-elide-constructors
extern int g1_80054134[];
extern int g2_80054134[];
extern int g3_80054134[];
extern int g4_80054134[];
extern int g5_80054134[];
extern int g6_80054134[];
extern void target_80054134(void*, void*, void*, void*, void*, void*, void*);

void func_80054134(void *self) {
    target_80054134(g1_80054134, g2_80054134, g3_80054134, g4_80054134, self, g5_80054134, g6_80054134);
}
