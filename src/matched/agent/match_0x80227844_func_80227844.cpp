// FLAGS: -fno-elide-constructors
extern int g1_80227844[];
extern int g2_80227844[];
extern int g3_80227844[];
extern int g4_80227844[];
extern int g5_80227844[];
extern int g6_80227844[];
extern void target_80227844(void*, void*, void*, void*, void*, void*, void*);

void func_80227844(void *self) {
    target_80227844(g1_80227844, g2_80227844, g3_80227844, g4_80227844, self, g5_80227844, g6_80227844);
}
