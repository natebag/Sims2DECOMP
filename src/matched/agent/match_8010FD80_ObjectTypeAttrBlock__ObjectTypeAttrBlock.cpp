// 0x8010FD80 (96 bytes)
// ObjectTypeAttrBlock::ObjectTypeAttrBlock(int, int)

class ObjectTypeAttrBlock { public: void ObjectTypeAttrBlock(int, int); };

__attribute__((naked))
void ObjectTypeAttrBlock::ObjectTypeAttrBlock(int, int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x28057CFF\n.long 0x909F0000\n.long 0x90BF0004\n.long 0x41810014\n.long 0x54A3083C\n.long 0x481C1441\n.long 0x907F0008\n.long 0x48000010\n.long 0x38000000\n.long 0x901F0008\n.long 0x901F0004\n.long 0x7FE3FB78\n.long 0x48000069\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
