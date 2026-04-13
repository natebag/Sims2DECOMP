// FLAGS: -fno-elide-constructors
extern int g1_80369F78[];
extern int g2_80369F78[];
extern int g3_80369F78[];
extern int g4_80369F78[];
extern int g5_80369F78[];
extern int g6_80369F78[];
extern void target_80369F78(void*, void*, void*, void*, void*, void*, void*);

void func_80369F78(void *self) {
    target_80369F78(g1_80369F78, g2_80369F78, g3_80369F78, g4_80369F78, self, g5_80369F78, g6_80369F78);
}
