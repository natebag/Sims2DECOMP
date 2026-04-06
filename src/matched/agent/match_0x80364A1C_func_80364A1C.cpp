// FLAGS: -fno-elide-constructors
extern int g1_80364A1C[];
extern int g2_80364A1C[];
extern int g3_80364A1C[];
extern int g4_80364A1C[];
extern int g5_80364A1C[];
extern int g6_80364A1C[];
extern void target_80364A1C(void*, void*, void*, void*, void*, void*, void*);

void func_80364A1C(void *self) {
    target_80364A1C(g1_80364A1C, g2_80364A1C, g3_80364A1C, g4_80364A1C, self, g5_80364A1C, g6_80364A1C);
}
