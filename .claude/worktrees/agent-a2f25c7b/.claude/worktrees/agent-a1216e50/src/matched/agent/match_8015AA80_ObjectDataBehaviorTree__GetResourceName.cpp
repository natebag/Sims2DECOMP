// 0x8015AA80 (84 bytes)
// ObjectDataBehaviorTree::GetResourceName(StringBuffer &) const

class ObjectDataBehaviorTree { public: void GetResourceName(StringBuffer &) const; };

__attribute__((naked))
void ObjectDataBehaviorTree::GetResourceName(StringBuffer &) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x3BE3000C\n.long 0x7C9E2378\n.long 0x7FE3FB78\n.long 0x4BF4BB51\n.long 0x2C030000\n.long 0x41820018\n.long 0x7FC3F378\n.long 0x7FE4FB78\n.long 0x4BF4BCB9\n.long 0x38600001\n.long 0x48000008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
