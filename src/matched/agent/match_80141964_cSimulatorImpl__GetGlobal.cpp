// 0x80141964 (112 bytes)
// cSimulatorImpl::GetGlobal(short)

class cSimulatorImpl { public: void GetGlobal(short); };

__attribute__((naked))
void cSimulatorImpl::GetGlobal(short) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9F2378\n.long 0x7C7E1B78\n.long 0x2C1F002E\n.long 0x41820010\n.long 0x2C1F002F\n.long 0x4182001C\n.long 0x48000028\n.long 0x3C608047\n.long 0x38635DCC\n.long 0x4BF009A1\n.long 0xB07E0070\n.long 0x48000014\n.long 0x3C608047\n.long 0x38635DCC\n.long 0x4BF0098D\n.long 0xB07E0072\n.long 0x7C1FFA14\n.long 0x393E0014\n.long 0x7C6902AE\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
