// FLAGS: -fno-elide-constructors
extern int g1_80321180[];
extern int g2_80321180[];
extern int g3_80321180[];
extern int g4_80321180[];
extern int g5_80321180[];
extern int g6_80321180[];
extern char g_result_80321180[4];
extern int target_80321180(void*, void*, void*, void*, int, void*, void*);

void func_80321180(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_80321180 = target_80321180(g1_80321180, g2_80321180, g3_80321180, g4_80321180, 0, g5_80321180, g6_80321180);
}
