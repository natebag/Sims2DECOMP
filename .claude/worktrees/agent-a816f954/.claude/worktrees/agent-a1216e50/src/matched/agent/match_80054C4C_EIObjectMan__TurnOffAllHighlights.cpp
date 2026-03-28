// 0x80054C4C (84 bytes)
// EIObjectMan::TurnOffAllHighlights(unsigned int)

class EIObjectMan { public: void TurnOffAllHighlights(unsigned int); };

__attribute__((naked))
void EIObjectMan::TurnOffAllHighlights(unsigned int) {
    asm volatile(".long 0x38000000\n.long 0x7C842379\n.long 0x41820010\n.long 0x2C040001\n.long 0x41820010\n.long 0x48000010\n.long 0x38000005\n.long 0x48000008\n.long 0x38000028\n.long 0x80630004\n.long 0x2C030000\n.long 0x4D820020\n.long 0x7C0B00F8\n.long 0x8123001C\n.long 0x8009032C\n.long 0x7C005838\n.long 0x9009032C\n.long 0x80630010\n.long 0x2C030000\n.long 0x4082FFE8\n.long 0x4E800020");
}
