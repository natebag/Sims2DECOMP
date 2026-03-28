// 0x801C6644 (72 bytes)
// MMUTarget::GetListItemName(char *)

class MMUTarget { public: void GetListItemName(char *); };

__attribute__((naked))
void MMUTarget::GetListItemName(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C691B78\n.long 0x8009008C\n.long 0x2C000001\n.long 0x4082000C\n.long 0x480003AD\n.long 0x48000018\n.long 0x2C000002\n.long 0x38600000\n.long 0x4082000C\n.long 0x7D234B78\n.long 0x480004DD\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
