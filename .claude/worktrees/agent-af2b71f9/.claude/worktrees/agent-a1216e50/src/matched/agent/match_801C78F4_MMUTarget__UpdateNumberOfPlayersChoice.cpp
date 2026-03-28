// 0x801C78F4 (68 bytes)
// MMUTarget::UpdateNumberOfPlayersChoice(char *, char *)

class MMUTarget { public: void UpdateNumberOfPlayersChoice(char *, char *); };

__attribute__((naked))
void MMUTarget::UpdateNumberOfPlayersChoice(char *, char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x7CA32B78\n.long 0x48117345\n.long 0x801E00C0\n.long 0x907E00C0\n.long 0x901E00C4\n.long 0x7FC3F378\n.long 0x48000059\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
