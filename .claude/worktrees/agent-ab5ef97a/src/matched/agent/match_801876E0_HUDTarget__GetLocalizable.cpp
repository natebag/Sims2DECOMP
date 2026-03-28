// 0x801876E0 (100 bytes)
// HUDTarget::GetLocalizable(char *)

class HUDTarget { public: void GetLocalizable(char *); };

__attribute__((naked))
void HUDTarget::GetLocalizable(char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C9F2378\n.long 0x7C7D1B78\n.long 0x887F0000\n.long 0x3BC00000\n.long 0x7C630774\n.long 0x480BAF8D\n.long 0x2C030000\n.long 0x41820014\n.long 0x893F0000\n.long 0x3BFF0001\n.long 0x7D290774\n.long 0x3BC9FFD0\n.long 0x7FA3EB78\n.long 0x7FC4F378\n.long 0x7FE5FB78\n.long 0x48000019\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
