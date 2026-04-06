// FLAGS: -fno-elide-constructors
extern int g1_802C5C2C[];
extern int g2_802C5C2C[];
extern int g3_802C5C2C[];
extern int g4_802C5C2C[];
extern int g5_802C5C2C[];
extern int g6_802C5C2C[];
extern char g_result_802C5C2C[4];
extern int target_802C5C2C(void*, void*, void*, void*, int, void*, void*);

void func_802C5C2C(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_802C5C2C = target_802C5C2C(g1_802C5C2C, g2_802C5C2C, g3_802C5C2C, g4_802C5C2C, 0, g5_802C5C2C, g6_802C5C2C);
}
