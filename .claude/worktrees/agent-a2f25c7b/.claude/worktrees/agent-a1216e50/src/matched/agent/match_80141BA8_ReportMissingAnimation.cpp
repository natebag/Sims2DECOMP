// 0x80141BA8 (108 bytes)
// ReportMissingAnimation(cXPerson *, char *, int)

__attribute__((naked))
void ReportMissingAnimation(cXPerson *, char *, int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38800043\n.long 0x813E0000\n.long 0x81490000\n.long 0x816A0018\n.long 0x800B002C\n.long 0xA86B0028\n.long 0x7C0803A6\n.long 0x7C6A1A14\n.long 0x4E800021\n.long 0x817E0000\n.long 0x38800043\n.long 0x812B0004\n.long 0xA8690110\n.long 0x80090114\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
