// 0x8027DAD8 AptActionInterpreter::_FunctionAptActionSetTarget(AptActionInterpreter (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,4; lwz 9,0x0(29); addi 9,9,3; rlwinm 31,9,0,0,29; addi 0,31,4; stw 0,0x0(29); lwz 4,0x0(31); lbz 0,0x0(4); extsb 30,0; cmpwi 30,0; bne 1f; lwz 11,0x8(29); cmpwi 11,0; beq 0f; lwz 9,0x8(11); lis 4,-32704; lis 5,-32704; addi 4,4,8388; lha 3,0x10(9); addi 5,5,6212; lwz 0,0x14(9); li 6,7574; add 3,11,3; mtspr 8,0; blrl; 0:; stw 30,0x8(29); b 6f; 1:; addi 30,1,8; mr 3,30; bl _s8027DAD8_0; lwz 9,0x0(31); lbz 11,0x0(9); addi 0,11,-46; cmplwi 0,1; bgt 4f; cmpwi 11,46; lwz 3,0x4(29); b 3f; 2:; lbzu 0,0x2(9); mr 3,11; cmpwi 0,46; 3:; bne 5f; lbz 0,0x1(9); cmpwi 0,46; bne 5f; lwz 0,0x48(3); mr 11,0; cmpwi 0,0; bne 2b; b 5f; 4:; lis 4,-32704; mr 3,30; addi 4,4,6544; bl _s8027DAD8_1; lwz 3,0x4(29); mr 5,30; li 4,0; bl _s8027DAD8_2; 5:; mr 11,3; li 0,0; stw 11,0x8(29); stw 0,0xc(29); lis 4,-32704; lis 5,-32704; addi 4,4,8388; lwz 9,0x8(11); addi 5,5,6212; li 6,7605; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 6f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027DAD8_3; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s8027DAD8_0();
extern "C" void _s8027DAD8_1();
extern "C" void _s8027DAD8_2();
extern "C" void _s8027DAD8_3();

struct AptActionInterpreter {
    void _FunctionAptActionSetTarget_AptActionI();
};

void AptActionInterpreter::_FunctionAptActionSetTarget_AptActionI() {
}
