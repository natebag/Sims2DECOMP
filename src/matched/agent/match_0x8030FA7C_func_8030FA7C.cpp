// FLAGS: -fno-elide-constructors
extern int g1_8030FA7C[];
extern int g2_8030FA7C[];
extern int g3_8030FA7C[];
extern int g4_8030FA7C[];
extern int g5_8030FA7C[];
extern int g6_8030FA7C[];
extern char g_result_8030FA7C[4];
extern int target_8030FA7C(void*, void*, void*, void*, int, void*, void*);

void func_8030FA7C(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_8030FA7C = target_8030FA7C(g1_8030FA7C, g2_8030FA7C, g3_8030FA7C, g4_8030FA7C, 0, g5_8030FA7C, g6_8030FA7C);
}
