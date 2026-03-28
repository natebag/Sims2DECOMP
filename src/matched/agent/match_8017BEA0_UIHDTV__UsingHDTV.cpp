// 0x8017BEA0 (84 bytes)
// UIHDTV::UsingHDTV(void)

class UIHDTV { public: void UsingHDTV(void); };

__attribute__((naked))
void UIHDTV::UsingHDTV(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x4800004D\n.long 0x7C7D1B78\n.long 0x7FC3F378\n.long 0x48000035\n.long 0x2C1D0280\n.long 0x4082000C\n.long 0x2C0301C0\n.long 0x4182000C\n.long 0x38600001\n.long 0x48000008\n.long 0x38600000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
