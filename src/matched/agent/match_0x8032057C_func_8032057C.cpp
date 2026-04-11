// FLAGS: -fno-elide-constructors
extern int g1_8032057C[];
extern int g2_8032057C[];
extern int g3_8032057C[];
extern int g4_8032057C[];
extern int g5_8032057C[];
extern int g6_8032057C[];
extern void target_8032057C(void*, void*, void*, void*, void*, void*, void*);

void func_8032057C(void *self) {
    target_8032057C(g1_8032057C, g2_8032057C, g3_8032057C, g4_8032057C, self, g5_8032057C, g6_8032057C);
}
