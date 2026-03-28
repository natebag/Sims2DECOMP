// 0x801CE920 (84 bytes)
// O2TTarget::SetTopLevelState(char *, char *)

class O2TTarget { public: void SetTopLevelState(char *, char *); };

__attribute__((naked))
void O2TTarget::SetTopLevelState(char *, char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x7CBC2B78\n.long 0x7C9D2378\n.long 0x7F83E378\n.long 0x48110311\n.long 0x801E0088\n.long 0x7FA4EB78\n.long 0x907E0088\n.long 0x7F85E378\n.long 0x901E008C\n.long 0x7FC3F378\n.long 0x48000019\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
