// FLAGS: -fno-elide-constructors
extern int g1_80313D64[];
extern int g2_80313D64[];
extern int g3_80313D64[];
extern int g4_80313D64[];
extern int g5_80313D64[];
extern int g6_80313D64[];
extern void target_80313D64(void*, void*, void*, void*, void*, void*, void*);

void func_80313D64(void *self) {
    target_80313D64(g1_80313D64, g2_80313D64, g3_80313D64, g4_80313D64, self, g5_80313D64, g6_80313D64);
}
