// 0x8027DE44 AptActionInterpreter::_FunctionAptActionPush(AptActionInterpreter (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lwz 9,0x0(4); li 29,0; mr 31,3; addi 9,9,3; rlwinm 30,9,0,0,29; addi 0,30,8; stw 0,0x0(4); lwz 9,0x0(30); cmpw 29,9; bge 6f; lis 26,-32704; lis 27,-32704; li 28,0; 0:; lwz 9,0x4(30); li 11,0; lwzx 3,28,9; lwz 0,0x0(3); rlwinm 9,0,0,25,31; cmpwi 9,8; bne 1f; rlwinm 11,0,5,31,31; 1:; cmpwi 11,0; beq 2f; lwz 9,0xc(3); lwz 11,0x38(31); rlwinm 9,9,2,0,29; lwzx 8,9,11; b 5f; 2:; cmpwi 9,4; li 9,0; bne 3f; rlwinm 9,0,5,31,31; 3:; cmpwi 9,0; beq 4f; lwz 3,0xc(3); bl _s8027DE44_0; 4:; mr 8,3; 5:; lwz 11,0x0(31); addi 4,26,5760; lwz 10,0x8(31); addi 5,27,5812; rlwinm 9,11,2,0,29; li 6,138; stwx 8,9,10; addi 11,11,1; stw 11,0x0(31); addi 29,29,1; addi 28,28,4; lwz 9,0x8(8); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,8,3; blrl; lwz 0,0x0(30); cmpw 29,0; blt 0b; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s8027DE44_0();

struct AptActionInterpreter {
    void _FunctionAptActionPush_AptActionInterp();
};

void AptActionInterpreter::_FunctionAptActionPush_AptActionInterp() {
}
