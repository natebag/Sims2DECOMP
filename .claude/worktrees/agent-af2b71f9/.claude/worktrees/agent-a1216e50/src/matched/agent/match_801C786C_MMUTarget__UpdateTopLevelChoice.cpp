// 0x801C786C (68 bytes)
// MMUTarget::UpdateTopLevelChoice(char *, char *)

class MMUTarget { public: void UpdateTopLevelChoice(char *, char *); };

__attribute__((naked))
void MMUTarget::UpdateTopLevelChoice(char *, char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x7CA32B78\n.long 0x481173CD\n.long 0x801E00A4\n.long 0x907E00A4\n.long 0x901E00A8\n.long 0x7FC3F378\n.long 0x480000A1\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
