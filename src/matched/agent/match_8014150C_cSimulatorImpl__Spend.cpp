// 0x8014150C (112 bytes)
// cSimulatorImpl::Spend(ExpenseType, int, cSimulator::tFundsPlayerNumber)

class cSimulatorImpl { public: void Spend(ExpenseType, int, cSimulator::tFundsPlayerNumber); };

__attribute__((naked))
void cSimulatorImpl::Spend(ExpenseType, int, cSimulator::tFundsPlayerNumber) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x7C9D2378\n.long 0x801E0078\n.long 0x7CBC2B78\n.long 0x809E0074\n.long 0x7CC53378\n.long 0x813E0000\n.long 0x7C840214\n.long 0x800900D4\n.long 0x7C9C2050\n.long 0xA86900D0\n.long 0x7C0803A6\n.long 0x7C7E1A14\n.long 0x4E800021\n.long 0x3BDE0154\n.long 0x57BD103A\n.long 0x7C1EE82E\n.long 0x7C00E214\n.long 0x7C1EE92E\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
