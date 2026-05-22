// 0x80141838 cSimulatorImpl::GetTodaysExpenses(ExpenseReport (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,340; li 9,24; 0:; lwz 0,0x0(3); addic. 9,9,-24; stw 0,0x0(4); lwz 0,0x4(3); stw 0,0x4(4); lwz 0,0x8(3); stw 0,0x8(4); lwz 0,0xc(3); stw 0,0xc(4); lwz 0,0x10(3); stw 0,0x10(4); lwz 0,0x14(3); addi 3,3,24; stw 0,0x14(4); addi 4,4,24; bne 0b; lwz 0,0x0(3); stw 0,0x0(4); lwz 0,0x4(3); stw 0,0x4(4)"
extern "C" void f_80141838() {}
