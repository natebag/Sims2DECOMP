// 0x8011A714 (92 bytes)
// ActionQueue::DisableHUDAccess(int)

class ActionQueue { public: void DisableHUDAccess(int); };

__attribute__((naked))
void ActionQueue::DisableHUDAccess(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x881F02B0\n.long 0x2C000000\n.long 0x4082002C\n.long 0x3D208047\n.long 0x80695BCC\n.long 0x2C030000\n.long 0x4182000C\n.long 0x889F02B1\n.long 0x4809E7BD\n.long 0x39200001\n.long 0x380000FF\n.long 0x981F02B1\n.long 0x993F02B0\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
