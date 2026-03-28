// 0x80190514 (96 bytes)
// SerializeUIGameData::SetupPlayerUIData(void)

class SerializeUIGameData { public: void SetupPlayerUIData(void); };

__attribute__((naked))
void SerializeUIGameData::SetupPlayerUIData(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x3FE08043\n.long 0x809F6C10\n.long 0x2C040000\n.long 0x41820014\n.long 0x38600000\n.long 0x38A00002\n.long 0x38C00000\n.long 0x48000225\n.long 0x809F6C10\n.long 0x2C040000\n.long 0x41820014\n.long 0x38600001\n.long 0x38A00002\n.long 0x38C00000\n.long 0x48000209\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
