// 0x8015B37C (104 bytes)
// IFFBehaviorTree::~IFFBehaviorTree(void)

class IFFBehaviorTree { public: void ~IFFBehaviorTree(void); };

__attribute__((naked))
void IFFBehaviorTree::~IFFBehaviorTree(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x3D208046\n.long 0x801F0008\n.long 0x392957D0\n.long 0x7C9E2378\n.long 0x913F0000\n.long 0x2C000000\n.long 0x4182001C\n.long 0x807F0054\n.long 0x2C030000\n.long 0x41820008\n.long 0x48175E9D\n.long 0x38000000\n.long 0x901F0054\n.long 0x7FE3FB78\n.long 0x7FC4F378\n.long 0x4BFFF5C5\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
