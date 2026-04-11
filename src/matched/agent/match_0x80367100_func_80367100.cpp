// FLAGS: -fno-elide-constructors
extern int g1_80367100[];
extern int g2_80367100[];
extern int g3_80367100[];
extern int g4_80367100[];
extern int g5_80367100[];
extern int g6_80367100[];
extern char g_result_80367100[4];
extern int target_80367100(void*, void*, void*, void*, int, void*, void*);

void func_80367100(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_80367100 = target_80367100(g1_80367100, g2_80367100, g3_80367100, g4_80367100, 0, g5_80367100, g6_80367100);
}
