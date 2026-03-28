// 0x801E95EC (92 bytes)
// SetVar_EYE_topLevelCurrSel::Handler(char *)

class SetVar_EYE_topLevelCurrSel { public: void Handler(char *); };

__attribute__((naked))
void SetVar_EYE_topLevelCurrSel::Handler(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C832378\n.long 0x480F5651\n.long 0x812D8FD8\n.long 0x2C030001\n.long 0x90690098\n.long 0x40820024\n.long 0x3FC08040\n.long 0xC03E87A8\n.long 0x4BE4FD95\n.long 0xC03E87A8\n.long 0x4BE4FE29\n.long 0xC03E87A8\n.long 0x4BE4FD19\n.long 0x4BE4FC11\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
