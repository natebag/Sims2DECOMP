// 0x80141894 (100 bytes)
// cSimulatorImpl::GetPreviousExpenses(int, ExpenseReport *)

class cSimulatorImpl { public: void GetPreviousExpenses(int, ExpenseReport *); };

__attribute__((naked))
void cSimulatorImpl::GetPreviousExpenses(int, ExpenseReport *) {
    asm volatile(".long 0x54842834\n.long 0x39200018\n.long 0x7C841A14\n.long 0x388400B4\n.long 0x80040000\n.long 0x3529FFE8\n.long 0x90050000\n.long 0x80040004\n.long 0x90050004\n.long 0x80040008\n.long 0x90050008\n.long 0x8004000C\n.long 0x9005000C\n.long 0x80040010\n.long 0x90050010\n.long 0x80040014\n.long 0x38840018\n.long 0x90050014\n.long 0x38A50018\n.long 0x4082FFC4\n.long 0x80040000\n.long 0x90050000\n.long 0x80040004\n.long 0x90050004\n.long 0x4E800020");
}
