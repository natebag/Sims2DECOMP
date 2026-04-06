// FLAGS: -fno-elide-constructors
extern int g1_80048440[];
extern int g2_80048440[];
extern int g3_80048440[];
extern int g4_80048440[];
extern int g5_80048440[];
extern int g6_80048440[];
extern void target_80048440(void*, void*, void*, void*, void*, void*, void*);

void func_80048440(void *self) {
    target_80048440(g1_80048440, g2_80048440, g3_80048440, g4_80048440, self, g5_80048440, g6_80048440);
}
