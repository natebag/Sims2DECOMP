// 0x8027DC4C AptActionInterpreter::_FunctionAptActionGotoLabel(AptActionInterpreter (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,4; addi 3,1,8; lwz 9,0x0(30); addi 9,9,3; rlwinm 9,9,0,0,29; addi 0,9,4; stw 0,0x0(30); lwz 4,0x0(9); bl _s8027DC4C_0; lwz 3,0x8(30); cmpwi 3,0; beq 1f; lwz 0,0x0(3); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 0f; rlwinm 11,0,5,31,31; 0:; cmpwi 11,0; mr 31,3; bne 2f; 1:; lwz 31,0x4(30); 2:; lwz 9,0x4c(31); addi 4,1,8; lwz 3,0x8(9); addi 3,3,8; bl _s8027DC4C_1; mr. 3,3; blt 3f; mr 4,3; mr 3,31; bl _s8027DC4C_2; lwz 9,0x4c(31); lwz 0,0x1c(9); rlwinm 0,0,0,26,24; stw 0,0x1c(9); 3:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 4f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027DC4C_3; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s8027DC4C_0();
extern "C" void _s8027DC4C_1();
extern "C" void _s8027DC4C_2();
extern "C" void _s8027DC4C_3();

struct AptActionInterpreter {
    void _FunctionAptActionGotoLabel_AptActionI();
};

void AptActionInterpreter::_FunctionAptActionGotoLabel_AptActionI() {
}
