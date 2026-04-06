// FLAGS: -fno-elide-constructors
extern int g1_80313BF4[];
extern int g2_80313BF4[];
extern int g3_80313BF4[];
extern int g4_80313BF4[];
extern int g5_80313BF4[];
extern int g6_80313BF4[];
extern char g_result_80313BF4[4];
extern int target_80313BF4(void*, void*, void*, void*, int, void*, void*);

void func_80313BF4(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_80313BF4 = target_80313BF4(g1_80313BF4, g2_80313BF4, g3_80313BF4, g4_80313BF4, 0, g5_80313BF4, g6_80313BF4);
}
