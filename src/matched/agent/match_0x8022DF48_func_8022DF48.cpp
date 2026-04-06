// FLAGS: -fno-elide-constructors
extern int g1_8022DF48[];
extern int g2_8022DF48[];
extern int g3_8022DF48[];
extern int g4_8022DF48[];
extern int g5_8022DF48[];
extern int g6_8022DF48[];
extern char g_result_8022DF48[4];
extern int target_8022DF48(void*, void*, void*, void*, int, void*, void*);

void func_8022DF48(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_8022DF48 = target_8022DF48(g1_8022DF48, g2_8022DF48, g3_8022DF48, g4_8022DF48, 0, g5_8022DF48, g6_8022DF48);
}
