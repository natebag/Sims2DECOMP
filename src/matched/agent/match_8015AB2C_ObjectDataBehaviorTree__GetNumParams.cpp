// 0x8015AB2C (104 bytes)
// ObjectDataBehaviorTree::GetNumParams(void) const

class ObjectDataBehaviorTree { public: void GetNumParams(void) const; };

__attribute__((naked))
void ObjectDataBehaviorTree::GetNumParams(void) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x4BFFFFBD\n.long 0x2C038002\n.long 0x41800010\n.long 0x813F0054\n.long 0x88690005\n.long 0x4800002C\n.long 0x7FE3FB78\n.long 0x4BFFFFA1\n.long 0x2C038001\n.long 0x40820018\n.long 0x813F0054\n.long 0x88090005\n.long 0x7C030378\n.long 0x28000004\n.long 0x40810008\n.long 0x38600004\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
