// FLAGS: -fno-elide-constructors
extern int g1_80227460[];
extern int g2_80227460[];
extern int g3_80227460[];
extern int g4_80227460[];
extern int g5_80227460[];
extern int g6_80227460[];
extern void target_80227460(void*, void*, void*, void*, void*, void*, void*);

void func_80227460(void *self) {
    target_80227460(g1_80227460, g2_80227460, g3_80227460, g4_80227460, self, g5_80227460, g6_80227460);
}
