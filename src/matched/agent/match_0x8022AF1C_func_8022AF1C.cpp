// FLAGS: -fno-elide-constructors
extern int g1_8022AF1C[];
extern int g2_8022AF1C[];
extern int g3_8022AF1C[];
extern int g4_8022AF1C[];
extern int g5_8022AF1C[];
extern int g6_8022AF1C[];
extern char g_result_8022AF1C[4];
extern int target_8022AF1C(void*, void*, void*, void*, int, void*, void*);

void func_8022AF1C(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_8022AF1C = target_8022AF1C(g1_8022AF1C, g2_8022AF1C, g3_8022AF1C, g4_8022AF1C, 0, g5_8022AF1C, g6_8022AF1C);
}
