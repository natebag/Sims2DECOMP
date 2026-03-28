// 0x80140D28 (72 bytes)
// cSimulatorImpl::ComputeTimeOfDay(void)

class cSimulatorImpl { public: void ComputeTimeOfDay(void); };

__attribute__((naked))
void cSimulatorImpl::ComputeTimeOfDay(void) {
    asm volatile(".long 0xA8030014\n.long 0x2C000005\n.long 0x4181000C\n.long 0x38600002\n.long 0x4E800020\n.long 0x2C000006\n.long 0x4181000C\n.long 0x38600003\n.long 0x4E800020\n.long 0x2C000011\n.long 0x4181000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x2C000012\n.long 0x38600002\n.long 0x4D810020\n.long 0x38600001\n.long 0x4E800020");
}
