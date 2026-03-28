// 0x8015C1A4 (68 bytes)
// ObjectDataObjDefinition::GetResourceName(StringBuffer *) const

class ObjectDataObjDefinition { public: void GetResourceName(StringBuffer *) const; };

__attribute__((naked))
void ObjectDataObjDefinition::GetResourceName(StringBuffer *) const {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C892378\n.long 0x80030008\n.long 0x80830004\n.long 0x7C002000\n.long 0x41820014\n.long 0x7D234B78\n.long 0x4BF4A561\n.long 0x38600001\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
