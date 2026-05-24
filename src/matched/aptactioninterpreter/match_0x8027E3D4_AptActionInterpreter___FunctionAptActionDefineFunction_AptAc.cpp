// 0x8027E3D4 AptActionInterpreter::_FunctionAptActionDefineFunction(AptActionInterpreter (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 31,4; mr 28,3; lwz 30,0x0(31); addi 27,1,8; mr 3,27; addi 30,30,3; rlwinm 30,30,0,0,29; addi 0,30,24; stw 0,0x0(31); lwz 9,0xc(30); add 0,0,9; stw 0,0x0(31); lwz 9,0x34(28); lwz 10,0x38(28); lwz 4,0x0(30); stw 9,0x10(30); stw 10,0x14(30); bl _s8027E3D4_0; lwz 3,-23016(13); li 4,56; lwz 29,0x4(31); bl _s8027E3D4_1; lwz 4,0x30(28); mr 5,30; mr 6,29; bl _s8027E3D4_2; lwz 4,0x0(30); mr 30,3; lbz 0,0x0(4); cmpwi 0,0; bne 0f; lwz 9,0x0(28); lis 4,-32704; lwz 10,0x8(28); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 30,11,10; addi 9,9,1; stw 9,0x0(28); addi 5,5,5812; li 6,138; lwz 9,0x8(30); lha 3,0x8(9); lwz 0,0xc(9); add 3,30,3; mtspr 8,0; blrl; b 3f; 0:; addi 3,1,16; bl _s8027E3D4_3; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027E3D4_4; 1:; lwz 4,0x10(1); stw 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027E3D4_5; 2:; lwz 5,0x8(31); mr 3,28; lwz 4,0x4(31); mr 6,27; mr 7,30; li 8,1; li 9,1; li 10,0; bl _s8027E3D4_6; 3:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 4f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027E3D4_7; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"

extern "C" void _s8027E3D4_0();
extern "C" void _s8027E3D4_1();
extern "C" void _s8027E3D4_2();
extern "C" void _s8027E3D4_3();
extern "C" void _s8027E3D4_4();
extern "C" void _s8027E3D4_5();
extern "C" void _s8027E3D4_6();
extern "C" void _s8027E3D4_7();

struct AptActionInterpreter {
    void _FunctionAptActionDefineFunction_AptAc();
};

void AptActionInterpreter::_FunctionAptActionDefineFunction_AptAc() {
}
