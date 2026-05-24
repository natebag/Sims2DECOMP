// 0x8027D7D8 AptActionInterpreter::_FunctionAptActionGotoFrame(AptActionInterpreter (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,0x0(4); mr 30,3; lwz 11,0x8(4); li 31,0; addi 9,9,3; rlwinm 8,9,0,0,29; cmpwi 11,0; addi 0,8,4; stw 0,0x0(4); beq 1f; lwz 0,0x0(11); li 10,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 0f; rlwinm 10,0,5,31,31; 0:; cmpwi 10,0; beq 1f; mr 31,11; b 3f; 1:; lwz 4,0x4(4); li 11,0; lwz 0,0x0(4); rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 2f; rlwinm 11,0,5,31,31; 2:; cmpwi 11,0; beq 3f; mr 31,4; 3:; cmpwi 31,0; beq 4f; lwz 4,0x0(8); mr 3,31; bl _s8027D7D8_0; lwz 9,0x4c(31); lwz 0,0x1c(9); rlwinm 0,0,0,26,24; stw 0,0x1c(9); 4:; lwz 3,-27600(13); lwz 0,0x4(3); cmpwi 0,0; beq 5f; lwz 0,0x0(30); cmpwi 0,0; bne 5f; bl _s8027D7D8_1; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8027D7D8_0();
extern "C" void _s8027D7D8_1();

struct AptActionInterpreter {
    void _FunctionAptActionGotoFrame_AptActionI();
};

void AptActionInterpreter::_FunctionAptActionGotoFrame_AptActionI() {
}
