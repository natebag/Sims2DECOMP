// 0x801ECD54 (112 bytes)
// StaticExtractObjSelectorGuidFromObject(cXObject *)

__attribute__((naked))
void StaticExtractObjSelectorGuidFromObject(cXObject *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C6B1B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000040\n.long 0x812B0004\n.long 0xA8690368\n.long 0x8009036C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C7F1B79\n.long 0x38600000\n.long 0x4182001C\n.long 0x7FE3FB78\n.long 0x4BF23AA5\n.long 0x7C631B79\n.long 0x40820008\n.long 0x7FE3FB78\n.long 0x4BF23B31\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
