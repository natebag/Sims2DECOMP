// 0x801419D4 (88 bytes)
// cSimulatorImpl::GetGlobalRef(short, short **)

class cSimulatorImpl { public: void GetGlobalRef(short, short **); };

__attribute__((naked))
void cSimulatorImpl::GetGlobalRef(short, short **) {
    asm volatile(".long 0x5480043E\n.long 0x7C6B1B78\n.long 0x2800002F\n.long 0x4081000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x2C040020\n.long 0x4182FFF4\n.long 0x40810018\n.long 0x2C04002F\n.long 0x41810018\n.long 0x2C04002E\n.long 0x41800010\n.long 0x4BFFFFDC\n.long 0x2C040003\n.long 0x4182FFD4\n.long 0x7D242214\n.long 0x38600001\n.long 0x39290014\n.long 0x7D2B4A14\n.long 0x91250000\n.long 0x4E800020");
}
