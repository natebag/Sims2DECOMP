// FLAGS: -fno-elide-constructors
extern int g1_80053FA0[];
extern int g2_80053FA0[];
extern int g3_80053FA0[];
extern int g4_80053FA0[];
extern int g5_80053FA0[];
extern int g6_80053FA0[];
extern void target_80053FA0(void*, void*, void*, void*, void*, void*, void*);

void func_80053FA0(void *self) {
    target_80053FA0(g1_80053FA0, g2_80053FA0, g3_80053FA0, g4_80053FA0, self, g5_80053FA0, g6_80053FA0);
}
