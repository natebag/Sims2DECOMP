// FLAGS: -fno-elide-constructors
extern int g1_8036987C[];
extern int g2_8036987C[];
extern int g3_8036987C[];
extern int g4_8036987C[];
extern int g5_8036987C[];
extern int g6_8036987C[];
extern void target_8036987C(void*, void*, void*, void*, void*, void*, void*);

void func_8036987C(void *self) {
    target_8036987C(g1_8036987C, g2_8036987C, g3_8036987C, g4_8036987C, self, g5_8036987C, g6_8036987C);
}
