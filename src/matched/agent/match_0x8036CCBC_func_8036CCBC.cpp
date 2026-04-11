// FLAGS: -fno-elide-constructors
extern int g1_8036CCBC[];
extern int g2_8036CCBC[];
extern int g3_8036CCBC[];
extern int g4_8036CCBC[];
extern int g5_8036CCBC[];
extern int g6_8036CCBC[];
extern char g_result_8036CCBC[4];
extern int target_8036CCBC(void*, void*, void*, void*, int, void*, void*);

void func_8036CCBC(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_8036CCBC = target_8036CCBC(g1_8036CCBC, g2_8036CCBC, g3_8036CCBC, g4_8036CCBC, 0, g5_8036CCBC, g6_8036CCBC);
}
