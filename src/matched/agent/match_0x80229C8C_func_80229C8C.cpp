// FLAGS: -fno-elide-constructors
extern int g1_80229C8C[];
extern int g2_80229C8C[];
extern int g3_80229C8C[];
extern int g4_80229C8C[];
extern int g5_80229C8C[];
extern int g6_80229C8C[];
extern void target_80229C8C(void*, void*, void*, void*, void*, void*, void*);

void func_80229C8C(void *self) {
    target_80229C8C(g1_80229C8C, g2_80229C8C, g3_80229C8C, g4_80229C8C, self, g5_80229C8C, g6_80229C8C);
}
