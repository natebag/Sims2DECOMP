// FLAGS: -fno-elide-constructors
extern int g1_8036842C[];
extern int g2_8036842C[];
extern int g3_8036842C[];
extern int g4_8036842C[];
extern int g5_8036842C[];
extern int g6_8036842C[];
extern char g_result_8036842C[4];
extern int target_8036842C(void*, void*, void*, void*, int, void*, void*);

void func_8036842C(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_8036842C = target_8036842C(g1_8036842C, g2_8036842C, g3_8036842C, g4_8036842C, 0, g5_8036842C, g6_8036842C);
}
