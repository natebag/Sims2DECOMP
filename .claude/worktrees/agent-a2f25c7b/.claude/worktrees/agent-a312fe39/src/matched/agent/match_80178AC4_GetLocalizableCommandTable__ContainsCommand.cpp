// 0x80178AC4 (96 bytes)
// GetLocalizableCommandTable::ContainsCommand(char *)

class GetLocalizableCommandTable { public: void ContainsCommand(char *); };

__attribute__((naked))
void GetLocalizableCommandTable::ContainsCommand(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x83E30000\n.long 0x7C9E2378\n.long 0x2C1F0000\n.long 0x4182002C\n.long 0x807F0008\n.long 0x7FC4F378\n.long 0x480CAD4D\n.long 0x2C030000\n.long 0x4082000C\n.long 0x38600001\n.long 0x48000014\n.long 0x83FF0004\n.long 0x2C1F0000\n.long 0x4082FFDC\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
