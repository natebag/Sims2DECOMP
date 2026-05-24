// 0x8014150C cSimulatorImpl::Spend(ExpenseType, (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 0,0x78(30); mr 28,5; lwz 4,0x74(30); mr 5,6; lwz 9,0x0(30); add 4,4,0; lwz 0,0xd4(9); subf 4,28,4; lha 3,0xd0(9); mtspr 8,0; add 3,30,3; blrl; addi 30,30,340; rlwinm 29,29,2,0,29; lwzx 0,30,29; add 0,0,28; stwx 0,30,29; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

struct cSimulatorImpl {
    void Spend_ExpenseType();
};

void cSimulatorImpl::Spend_ExpenseType() {
}
