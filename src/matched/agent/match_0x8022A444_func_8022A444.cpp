// FLAGS: -fno-elide-constructors
extern int g1_8022A444[];
extern int g2_8022A444[];
extern int g3_8022A444[];
extern int g4_8022A444[];
extern int g5_8022A444[];
extern int g6_8022A444[];
extern char g_result_8022A444[4];
extern int target_8022A444(void*, void*, void*, void*, int, void*, void*);

void func_8022A444(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_8022A444 = target_8022A444(g1_8022A444, g2_8022A444, g3_8022A444, g4_8022A444, 0, g5_8022A444, g6_8022A444);
}
