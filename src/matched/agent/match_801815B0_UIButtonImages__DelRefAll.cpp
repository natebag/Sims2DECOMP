// 0x801815B0 (84 bytes)
// UIButtonImages::DelRefAll(void)

class UIButtonImages { public: void DelRefAll(void); };

__attribute__((naked))
void UIButtonImages::DelRefAll(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x3F80804C\n.long 0x3BBE0034\n.long 0x7FDFF378\n.long 0x809F0000\n.long 0x387CBBDC\n.long 0x3BFF0004\n.long 0x481A5B31\n.long 0x7C1FE800\n.long 0x4081FFEC\n.long 0x38000000\n.long 0x901E00A8\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
