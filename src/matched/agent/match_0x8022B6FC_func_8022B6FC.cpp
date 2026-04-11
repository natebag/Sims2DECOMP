// FLAGS: -fno-elide-constructors
extern int g1_8022B6FC[];
extern int g2_8022B6FC[];
extern int g3_8022B6FC[];
extern int g4_8022B6FC[];
extern int g5_8022B6FC[];
extern int g6_8022B6FC[];
extern char g_result_8022B6FC[4];
extern int target_8022B6FC(void*, void*, void*, void*, int, void*, void*);

void func_8022B6FC(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_8022B6FC = target_8022B6FC(g1_8022B6FC, g2_8022B6FC, g3_8022B6FC, g4_8022B6FC, 0, g5_8022B6FC, g6_8022B6FC);
}
