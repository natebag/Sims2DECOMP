// FLAGS: -fno-elide-constructors
extern int g1_80229B28[];
extern int g2_80229B28[];
extern int g3_80229B28[];
extern int g4_80229B28[];
extern int g5_80229B28[];
extern int g6_80229B28[];
extern char g_result_80229B28[4];
extern int target_80229B28(void*, void*, void*, void*, int, void*, void*);

void func_80229B28(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_80229B28 = target_80229B28(g1_80229B28, g2_80229B28, g3_80229B28, g4_80229B28, 0, g5_80229B28, g6_80229B28);
}
