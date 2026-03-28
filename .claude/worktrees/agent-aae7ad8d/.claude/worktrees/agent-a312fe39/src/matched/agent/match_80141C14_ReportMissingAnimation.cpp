// 0x80141C14 (108 bytes)
// ReportMissingAnimation(cXObject *, cXPerson *, AnimTable *, int)

__attribute__((naked))
void ReportMissingAnimation(cXObject *, cXPerson *, AnimTable *, int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9E2378\n.long 0x817E0000\n.long 0x38800043\n.long 0x814B0000\n.long 0x812A0018\n.long 0x8009002C\n.long 0xA8690028\n.long 0x7C0803A6\n.long 0x7C6A1A14\n.long 0x4E800021\n.long 0x817E0000\n.long 0x38800043\n.long 0x812B0004\n.long 0xA8690110\n.long 0x80090114\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
