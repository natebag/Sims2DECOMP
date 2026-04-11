// FLAGS: -fno-elide-constructors
extern int g1_80368598[];
extern int g2_80368598[];
extern int g3_80368598[];
extern int g4_80368598[];
extern int g5_80368598[];
extern int g6_80368598[];
extern void target_80368598(void*, void*, void*, void*, void*, void*, void*);

void func_80368598(void *self) {
    target_80368598(g1_80368598, g2_80368598, g3_80368598, g4_80368598, self, g5_80368598, g6_80368598);
}
