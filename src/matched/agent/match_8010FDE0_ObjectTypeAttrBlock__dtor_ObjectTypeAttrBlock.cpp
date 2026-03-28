// 0x8010FDE0 (76 bytes)
// ObjectTypeAttrBlock::~ObjectTypeAttrBlock(void)

class ObjectTypeAttrBlock { public: void ~ObjectTypeAttrBlock(void); };

__attribute__((naked))
void ObjectTypeAttrBlock::~ObjectTypeAttrBlock(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x807F0008\n.long 0x2C030000\n.long 0x41820008\n.long 0x481C1451\n.long 0x73C00001\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x481C140D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
