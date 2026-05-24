// 0x80280978 AptActionInterpreter::_FunctionAptActionBranchIfFalse(AptActionInterpreter (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 31,3; lwz 9,0x0(30); addi 9,9,3; rlwinm 29,9,0,0,29; addi 0,29,4; stw 0,0x0(30); lwz 9,0x0(31); lwz 0,0x8(31); rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s80280978_0; cmpwi 3,0; bne 0f; lwz 9,0x0(29); lwz 0,0x0(30); add 0,0,9; stw 0,0x0(30); 0:; lwz 9,0x0(31); cmpwi 9,0; ble 1f; lwz 0,0x8(31); rlwinm 9,9,2,0,29; lis 4,-32704; lis 5,-32704; add 9,9,0; addi 4,4,5964; lwz 11,-4(9); addi 5,5,5812; li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(31); addi 9,9,-1; stw 9,0x0(31); 1:; lwz 3,-27600(13); lwz 0,0x4(3); cmpwi 0,0; beq 2f; lwz 0,0x0(31); cmpwi 0,0; bne 2f; bl _s80280978_1; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80280978_0();
extern "C" void _s80280978_1();

struct AptActionInterpreter {
    void _FunctionAptActionBranchIfFalse_AptAct();
};

void AptActionInterpreter::_FunctionAptActionBranchIfFalse_AptAct() {
}
