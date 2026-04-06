/* __static_initialization_and_destruction_0 at 0x801E6F08 (36B) */

extern char g_801E6F08[4];

void func_801E6F08(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_801E6F08 = 17;
}
