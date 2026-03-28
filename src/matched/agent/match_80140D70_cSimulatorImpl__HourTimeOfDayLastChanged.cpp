// 0x80140D70 (88 bytes)
// cSimulatorImpl::HourTimeOfDayLastChanged(void)

class cSimulatorImpl { public: void HourTimeOfDayLastChanged(void); };

__attribute__((naked))
void cSimulatorImpl::HourTimeOfDayLastChanged(void) {
    asm volatile(".long 0xA803001C\n.long 0x2C000001\n.long 0x41820038\n.long 0x41810010\n.long 0x2C000000\n.long 0x41820034\n.long 0x48000038\n.long 0x2C000002\n.long 0x41820010\n.long 0x2C000003\n.long 0x41820010\n.long 0x48000024\n.long 0x38600013\n.long 0x4E800020\n.long 0x38600006\n.long 0x4E800020\n.long 0x38600012\n.long 0x4E800020\n.long 0x38600007\n.long 0x4E800020\n.long 0x3860FFFF\n.long 0x4E800020");
}
