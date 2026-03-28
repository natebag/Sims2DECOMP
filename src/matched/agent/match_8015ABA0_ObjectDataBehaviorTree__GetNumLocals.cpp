// 0x8015ABA0 (112 bytes)
// ObjectDataBehaviorTree::GetNumLocals(void) const

class ObjectDataBehaviorTree { public: void GetNumLocals(void) const; };

__attribute__((naked))
void ObjectDataBehaviorTree::GetNumLocals(void) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x4BFFFF49\n.long 0x2C038002\n.long 0x41800010\n.long 0x813F0054\n.long 0x88690006\n.long 0x48000034\n.long 0x7FE3FB78\n.long 0x4BFFFF2D\n.long 0x2C038001\n.long 0x40820020\n.long 0x813F0054\n.long 0x88090006\n.long 0x7C030378\n.long 0x28000004\n.long 0x40810010\n.long 0x38600004\n.long 0x48000008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
