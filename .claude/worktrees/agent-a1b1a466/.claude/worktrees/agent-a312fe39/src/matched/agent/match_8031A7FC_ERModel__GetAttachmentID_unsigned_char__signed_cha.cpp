// 0x8031A7FC (80 bytes)
// ERModel::GetAttachmentID(unsigned char, signed char &)

class ERModel { public: void GetAttachmentID(unsigned char, signed char &); };

__attribute__((naked))
void ERModel::GetAttachmentID(unsigned char, signed char &) {
    asm volatile(".long 0x80030138\n.long 0x39600000\n.long 0x7C0B0000\n.long 0x4080003C\n.long 0x39400000\n.long 0x8123013C\n.long 0x7D2A4A14\n.long 0x88090007\n.long 0x7C002000\n.long 0x40820010\n.long 0x99650000\n.long 0x38600001\n.long 0x4E800020\n.long 0x80030138\n.long 0x396B0001\n.long 0x394A0040\n.long 0x7C0B0000\n.long 0x4180FFD0\n.long 0x38600000\n.long 0x4E800020");
}
