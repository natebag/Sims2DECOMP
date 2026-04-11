// FLAGS: -fno-elide-constructors
extern int g1_80035138[];
extern int g2_80035138[];
extern int g3_80035138[];
extern int g4_80035138[];
extern int g5_80035138[];
extern int g6_80035138[];
extern void target_80035138(void*, void*, void*, void*, void*, void*, void*);

void func_80035138(void *self) {
    target_80035138(g1_80035138, g2_80035138, g3_80035138, g4_80035138, self, g5_80035138, g6_80035138);
}
