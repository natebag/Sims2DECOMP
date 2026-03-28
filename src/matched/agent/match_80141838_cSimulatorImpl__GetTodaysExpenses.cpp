// 0x80141838 (92 bytes)
// cSimulatorImpl::GetTodaysExpenses(ExpenseReport *)

class cSimulatorImpl { public: void GetTodaysExpenses(ExpenseReport *); };

__attribute__((naked))
void cSimulatorImpl::GetTodaysExpenses(ExpenseReport *) {
    asm volatile(".long 0x38630154\n.long 0x39200018\n.long 0x80030000\n.long 0x3529FFE8\n.long 0x90040000\n.long 0x80030004\n.long 0x90040004\n.long 0x80030008\n.long 0x90040008\n.long 0x8003000C\n.long 0x9004000C\n.long 0x80030010\n.long 0x90040010\n.long 0x80030014\n.long 0x38630018\n.long 0x90040014\n.long 0x38840018\n.long 0x4082FFC4\n.long 0x80030000\n.long 0x90040000\n.long 0x80030004\n.long 0x90040004\n.long 0x4E800020");
}
