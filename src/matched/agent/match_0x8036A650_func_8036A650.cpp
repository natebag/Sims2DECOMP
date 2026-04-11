// FLAGS: -fno-elide-constructors
extern int g1_8036A650[];
extern int g2_8036A650[];
extern int g3_8036A650[];
extern int g4_8036A650[];
extern int g5_8036A650[];
extern int g6_8036A650[];
extern void target_8036A650(void*, void*, void*, void*, void*, void*, void*);

void func_8036A650(void *self) {
    target_8036A650(g1_8036A650, g2_8036A650, g3_8036A650, g4_8036A650, self, g5_8036A650, g6_8036A650);
}
