// 0x8027FA30 AptActionInterpreter::_FunctionAptActionPushStringGetVar(AptActionInterpreter (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lwz 9,0x0(31); addi 3,1,8; addi 9,9,3; rlwinm 9,9,0,0,29; addi 0,9,4; stw 0,0x0(31); lwz 4,0x0(9); bl _s8027FA30_0; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,-23024(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027FA30_1; 0:; lwz 4,0x8(1); stw 4,-23024(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027FA30_2; 1:; lwz 5,0x8(31); addi 6,13,-23024; lwz 4,0x4(31); li 9,0; mr 3,30; li 7,1; li 8,1; bl _s8027FA30_3; lwz 9,0x0(30); lis 4,-32704; lwz 10,0x8(30); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 3,11,10; addi 9,9,1; stw 9,0x0(30); addi 5,5,5812; li 6,138; lwz 9,0x8(3); lha 0,0x8(9); lwz 9,0xc(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s8027FA30_0();
extern "C" void _s8027FA30_1();
extern "C" void _s8027FA30_2();
extern "C" void _s8027FA30_3();

struct AptActionInterpreter {
    void _FunctionAptActionPushStringGetVar_Apt();
};

void AptActionInterpreter::_FunctionAptActionPushStringGetVar_Apt() {
}
