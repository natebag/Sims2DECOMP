/* global init + address registration at 0x80226DCC (112B) */
// FLAGS: -fno-elide-constructors
extern int g1_80226DCC[];
extern int g2_80226DCC[];
extern int g3_80226DCC[];
extern int g4_80226DCC[];
extern int g5_80226DCC[];
extern int g6_80226DCC[];
extern char g_result_80226DCC[4];
extern int target_80226DCC(void*, void*, void*, void*, int, void*, void*);

void func_80226DCC(int priority, unsigned int selector) {
    if (selector != 0xFFFF) return;
    if (priority == 0) return;
    *(int*)g_result_80226DCC = target_80226DCC(g1_80226DCC, g2_80226DCC, g3_80226DCC, g4_80226DCC, 0, g5_80226DCC, g6_80226DCC);
}
