// 0x801C1D08 (104 bytes)
// M2MTarget::DoesMemoryDeviceExist(void)

class M2MTarget { public: void DoesMemoryDeviceExist(void); };

__attribute__((naked))
void M2MTarget::DoesMemoryDeviceExist(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFC10010\n.long 0x9001001C\n.long 0x3BC00000\n.long 0x38810008\n.long 0x93C10008\n.long 0x38600000\n.long 0x4BEB32E1\n.long 0x93C1000C\n.long 0x38600001\n.long 0x3881000C\n.long 0x4BEB32D1\n.long 0x80010008\n.long 0x38600000\n.long 0x2C000000\n.long 0x40820010\n.long 0x8001000C\n.long 0x2C000000\n.long 0x41820008\n.long 0x38600001\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBC10010\n.long 0x38210018\n.long 0x4E800020");
}
