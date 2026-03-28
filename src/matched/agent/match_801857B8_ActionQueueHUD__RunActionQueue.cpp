// 0x801857B8 (104 bytes)
// ActionQueueHUD::RunActionQueue(void)

class ActionQueueHUD { public: void RunActionQueue(void); };

__attribute__((naked))
void ActionQueueHUD::RunActionQueue(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x893F030A\n.long 0x2C090000\n.long 0x41820038\n.long 0x3809FFFF\n.long 0x5409063E\n.long 0x981F030A\n.long 0x2C090000\n.long 0x4082001C\n.long 0x4BFFFDE5\n.long 0x881F0308\n.long 0x2C000000\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4BFFFBFD\n.long 0x7FE3FB78\n.long 0x48000019\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
