// FLAGS: -fno-elide-constructors
extern int g1_80368C8C[];
extern int g2_80368C8C[];
extern int g3_80368C8C[];
extern int g4_80368C8C[];
extern int g5_80368C8C[];
extern int g6_80368C8C[];
extern void target_80368C8C(void*, void*, void*, void*, void*, void*, void*);

void func_80368C8C(void *self) {
    target_80368C8C(g1_80368C8C, g2_80368C8C, g3_80368C8C, g4_80368C8C, self, g5_80368C8C, g6_80368C8C);
}
