// 0x8015BEE8 (72 bytes)
// ObjectDataObjDefinition::Reset(void)

class ObjectDataObjDefinition { public: void Reset(void); };

__attribute__((naked))
void ObjectDataObjDefinition::Reset(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x881F001A\n.long 0x2C000000\n.long 0x41820018\n.long 0x807F001C\n.long 0x48175315\n.long 0x38000000\n.long 0x981F001A\n.long 0x901F001C\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
