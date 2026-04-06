// FLAGS: -fno-elide-constructors
extern int g1_8036726C[];
extern int g2_8036726C[];
extern int g3_8036726C[];
extern int g4_8036726C[];
extern int g5_8036726C[];
extern int g6_8036726C[];
extern void target_8036726C(void*, void*, void*, void*, void*, void*, void*);

void func_8036726C(void *self) {
    target_8036726C(g1_8036726C, g2_8036726C, g3_8036726C, g4_8036726C, self, g5_8036726C, g6_8036726C);
}
