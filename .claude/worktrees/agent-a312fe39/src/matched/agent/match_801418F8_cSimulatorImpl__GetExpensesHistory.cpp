// 0x801418F8 (108 bytes)
// cSimulatorImpl::GetExpensesHistory(ExpenseReport *)

class cSimulatorImpl { public: void GetExpensesHistory(ExpenseReport *); };

__attribute__((naked))
void cSimulatorImpl::GetExpensesHistory(ExpenseReport *) {
    asm volatile(".long 0x9421FFE8\n.long 0x39230154\n.long 0x380300B4\n.long 0x386300D4\n.long 0x91210010\n.long 0x90010008\n.long 0x39200000\n.long 0x9061000C\n.long 0x38A10008\n.long 0x38000003\n.long 0x5527103A\n.long 0x7C0903A6\n.long 0x38C90001\n.long 0x7CE83B78\n.long 0x39400000\n.long 0x7CAB2B78\n.long 0x812B0000\n.long 0x396B0004\n.long 0x7C09402E\n.long 0x7D4A0214\n.long 0x4200FFF0\n.long 0x7CC93378\n.long 0x7D44392E\n.long 0x2C090007\n.long 0x4081FFC4\n.long 0x38210018\n.long 0x4E800020");
}
