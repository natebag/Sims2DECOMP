// FLAGS: -fno-elide-constructors
extern int g1_803648B4[];
extern int g2_803648B4[];
extern int g3_803648B4[];
extern int g4_803648B4[];
extern int g5_803648B4[];
extern int g6_803648B4[];
extern void target_803648B4(void*, void*, void*, void*, void*, void*, void*);

void func_803648B4(void *self) {
    target_803648B4(g1_803648B4, g2_803648B4, g3_803648B4, g4_803648B4, self, g5_803648B4, g6_803648B4);
}
