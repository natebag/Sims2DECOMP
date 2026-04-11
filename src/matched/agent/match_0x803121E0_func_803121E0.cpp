// FLAGS: -fno-elide-constructors
extern int g1_803121E0[];
extern int g2_803121E0[];
extern int g3_803121E0[];
extern int g4_803121E0[];
extern int g5_803121E0[];
extern int g6_803121E0[];
extern void target_803121E0(void*, void*, void*, void*, void*, void*, void*);

void func_803121E0(void *self) {
    target_803121E0(g1_803121E0, g2_803121E0, g3_803121E0, g4_803121E0, self, g5_803121E0, g6_803121E0);
}
