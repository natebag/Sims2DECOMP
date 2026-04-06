// FLAGS: -fno-elide-constructors
extern int g1_80227EEC[];
extern int g2_80227EEC[];
extern int g3_80227EEC[];
extern int g4_80227EEC[];
extern int g5_80227EEC[];
extern int g6_80227EEC[];
extern char g_result_80227EEC[4];
extern int target_80227EEC(void*, void*, void*, void*, int, void*, void*);

void func_80227EEC(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_80227EEC = target_80227EEC(g1_80227EEC, g2_80227EEC, g3_80227EEC, g4_80227EEC, 0, g5_80227EEC, g6_80227EEC);
}
