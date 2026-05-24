// 0x8027FCE4 AptActionInterpreter::_FunctionAptActionPushStringSetVar(AptActionInterpreter (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 28,4; lwz 31,-26892(13); lwz 9,0x0(28); mr 29,3; cmpwi 31,0; addi 9,9,3; rlwinm 27,9,0,0,29; addi 0,27,4; stw 0,0x0(28); beq 2f; lwz 0,0x0(31); lwz 9,0x10(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 1:; addi 30,31,12; mr 3,30; bl _s8027FCE4_0; cmpwi 3,0; bne 3f; mr 3,30; li 4,0; bl _s8027FCE4_1; b 3f; 2:; lwz 3,-23020(13); li 4,20; bl _s8027FCE4_2; bl _s8027FCE4_3; mr 31,3; 3:; lwz 4,0x0(27); addi 3,1,8; bl _s8027FCE4_4; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 4f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027FCE4_5; 4:; lwz 0,0x8(1); stw 0,0xc(31); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027FCE4_6; 5:; lwz 9,0x0(29); lis 4,-32704; lwz 10,0x8(29); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 31,11,10; addi 9,9,1; stw 9,0x0(29); addi 5,5,5812; li 6,138; lwz 9,0x8(31); lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; mr 3,29; mr 4,28; bl _s8027FCE4_7; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s8027FCE4_0();
extern "C" void _s8027FCE4_1();
extern "C" void _s8027FCE4_2();
extern "C" void _s8027FCE4_3();
extern "C" void _s8027FCE4_4();
extern "C" void _s8027FCE4_5();
extern "C" void _s8027FCE4_6();
extern "C" void _s8027FCE4_7();

struct AptActionInterpreter {
    void _FunctionAptActionPushStringSetVar_Apt();
};

void AptActionInterpreter::_FunctionAptActionPushStringSetVar_Apt() {
}
