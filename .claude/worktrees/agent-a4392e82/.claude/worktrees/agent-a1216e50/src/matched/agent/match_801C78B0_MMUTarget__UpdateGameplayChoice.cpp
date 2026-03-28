// 0x801C78B0 (68 bytes)
// MMUTarget::UpdateGameplayChoice(char *, char *)

class MMUTarget { public: void UpdateGameplayChoice(char *, char *); };

__attribute__((naked))
void MMUTarget::UpdateGameplayChoice(char *, char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x7CA32B78\n.long 0x48117389\n.long 0x801E00B8\n.long 0x907E00B8\n.long 0x901E00BC\n.long 0x7FC3F378\n.long 0x4800007D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
