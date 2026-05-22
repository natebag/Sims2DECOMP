// 0x801418F8 cSimulatorImpl::GetExpensesHistory(ExpenseReport (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); addi 9,3,340; addi 0,3,180; addi 3,3,212; stw 9,0x10(1); stw 0,0x8(1); li 9,0; stw 3,0xc(1); addi 5,1,8; 0:; li 0,3; rlwinm 7,9,2,0,29; mtspr 9,0; addi 6,9,1; mr 8,7; li 10,0; mr 11,5; 1:; lwz 9,0x0(11); addi 11,11,4; lwzx 0,9,8; add 10,10,0; bdnz 1b; mr 9,6; stwx 10,4,7; cmpwi 9,7; ble 0b; addi 1,1,24"
extern "C" void f_801418F8() {}
