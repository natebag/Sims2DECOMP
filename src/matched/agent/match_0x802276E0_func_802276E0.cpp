// FLAGS: -fno-elide-constructors
extern int g1_802276E0[];
extern int g2_802276E0[];
extern int g3_802276E0[];
extern int g4_802276E0[];
extern int g5_802276E0[];
extern int g6_802276E0[];
extern char g_result_802276E0[4];
extern int target_802276E0(void*, void*, void*, void*, int, void*, void*);

void func_802276E0(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_802276E0 = target_802276E0(g1_802276E0, g2_802276E0, g3_802276E0, g4_802276E0, 0, g5_802276E0, g6_802276E0);
}
