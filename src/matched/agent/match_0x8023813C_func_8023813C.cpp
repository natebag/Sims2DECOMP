// FLAGS: -fno-elide-constructors
extern int g1_8023813C[];
extern int g2_8023813C[];
extern int g3_8023813C[];
extern int g4_8023813C[];
extern int g5_8023813C[];
extern int g6_8023813C[];
extern void target_8023813C(void*, void*, void*, void*, void*, void*, void*);

void func_8023813C(void *self) {
    target_8023813C(g1_8023813C, g2_8023813C, g3_8023813C, g4_8023813C, self, g5_8023813C, g6_8023813C);
}
