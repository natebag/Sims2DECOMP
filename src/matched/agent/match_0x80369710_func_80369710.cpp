// FLAGS: -fno-elide-constructors
extern int g1_80369710[];
extern int g2_80369710[];
extern int g3_80369710[];
extern int g4_80369710[];
extern int g5_80369710[];
extern int g6_80369710[];
extern char g_result_80369710[4];
extern int target_80369710(void*, void*, void*, void*, int, void*, void*);

void func_80369710(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_80369710 = target_80369710(g1_80369710, g2_80369710, g3_80369710, g4_80369710, 0, g5_80369710, g6_80369710);
}
