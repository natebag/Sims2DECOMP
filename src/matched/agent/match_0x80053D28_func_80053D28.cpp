// FLAGS: -fno-elide-constructors
extern int g1_80053D28[];
extern int g2_80053D28[];
extern int g3_80053D28[];
extern int g4_80053D28[];
extern int g5_80053D28[];
extern int g6_80053D28[];
extern void target_80053D28(void*, void*, void*, void*, void*, void*, void*);

void func_80053D28(void *self) {
    target_80053D28(g1_80053D28, g2_80053D28, g3_80053D28, g4_80053D28, self, g5_80053D28, g6_80053D28);
}
