// FLAGS: -fno-elide-constructors
extern int g1_8022B860[];
extern int g2_8022B860[];
extern int g3_8022B860[];
extern int g4_8022B860[];
extern int g5_8022B860[];
extern int g6_8022B860[];
extern void target_8022B860(void*, void*, void*, void*, void*, void*, void*);

void func_8022B860(void *self) {
    target_8022B860(g1_8022B860, g2_8022B860, g3_8022B860, g4_8022B860, self, g5_8022B860, g6_8022B860);
}
