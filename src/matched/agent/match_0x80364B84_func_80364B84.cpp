// FLAGS: -fno-elide-constructors
extern int g1_80364B84[];
extern int g2_80364B84[];
extern int g3_80364B84[];
extern int g4_80364B84[];
extern int g5_80364B84[];
extern int g6_80364B84[];
extern void target_80364B84(void*, void*, void*, void*, void*, void*, void*);

void func_80364B84(void *self) {
    target_80364B84(g1_80364B84, g2_80364B84, g3_80364B84, g4_80364B84, self, g5_80364B84, g6_80364B84);
}
