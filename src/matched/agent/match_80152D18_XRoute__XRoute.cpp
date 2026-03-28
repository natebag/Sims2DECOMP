// 0x80152D18 (92 bytes)
// XRoute::XRoute(void)

class XRoute { public: void XRoute(void); };

__attribute__((naked))
void XRoute::XRoute(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFC10010\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x38000000\n.long 0x901E0000\n.long 0x393E0008\n.long 0x901E0004\n.long 0x387E0010\n.long 0x90090004\n.long 0x4BFEFC51\n.long 0x7FC3F378\n.long 0x38800000\n.long 0x38A00000\n.long 0x38C00000\n.long 0x48000085\n.long 0x7FC3F378\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBC10010\n.long 0x38210018\n.long 0x4E800020");
}
