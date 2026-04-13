// FLAGS: -fno-elide-constructors
extern int g1_8036C0C0[];
extern int g2_8036C0C0[];
extern int g3_8036C0C0[];
extern int g4_8036C0C0[];
extern int g5_8036C0C0[];
extern int g6_8036C0C0[];
extern char g_result_8036C0C0[4];
extern int target_8036C0C0(void*, void*, void*, void*, int, void*, void*);

void func_8036C0C0(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_8036C0C0 = target_8036C0C0(g1_8036C0C0, g2_8036C0C0, g3_8036C0C0, g4_8036C0C0, 0, g5_8036C0C0, g6_8036C0C0);
}
