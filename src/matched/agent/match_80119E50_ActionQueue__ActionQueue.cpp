// 0x80119E50 (96 bytes)
// ActionQueue::ActionQueue(void)

class ActionQueue { public: void ActionQueue(void); };

__attribute__((naked))
void ActionQueue::ActionQueue(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7D1B78\n.long 0x3BC00009\n.long 0x7FBFEB78\n.long 0x7FE3FB78\n.long 0x4BFA72D1\n.long 0x3BFF0044\n.long 0x2C1E0000\n.long 0x3BDEFFFF\n.long 0x4082FFEC\n.long 0x39200000\n.long 0x38000001\n.long 0x913D02A8\n.long 0x7FA3EB78\n.long 0x981D02B0\n.long 0x913D02AC\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
