// FLAGS: -fno-elide-constructors
extern int g1_80368B1C[];
extern int g2_80368B1C[];
extern int g3_80368B1C[];
extern int g4_80368B1C[];
extern int g5_80368B1C[];
extern int g6_80368B1C[];
extern char g_result_80368B1C[4];
extern int target_80368B1C(void*, void*, void*, void*, int, void*, void*);

void func_80368B1C(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_80368B1C = target_80368B1C(g1_80368B1C, g2_80368B1C, g3_80368B1C, g4_80368B1C, 0, g5_80368B1C, g6_80368B1C);
}
