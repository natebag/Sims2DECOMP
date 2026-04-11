// FLAGS: -fno-elide-constructors
extern int g1_802272FC[];
extern int g2_802272FC[];
extern int g3_802272FC[];
extern int g4_802272FC[];
extern int g5_802272FC[];
extern int g6_802272FC[];
extern char g_result_802272FC[4];
extern int target_802272FC(void*, void*, void*, void*, int, void*, void*);

void func_802272FC(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_802272FC = target_802272FC(g1_802272FC, g2_802272FC, g3_802272FC, g4_802272FC, 0, g5_802272FC, g6_802272FC);
}
