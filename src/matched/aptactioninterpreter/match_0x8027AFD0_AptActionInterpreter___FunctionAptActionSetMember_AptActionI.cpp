// 0x8027AFD0 AptActionInterpreter::_FunctionAptActionSetMember(AptActionInterpreter (872 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 28,3; mr 26,4; lwz 9,0x0(28); li 8,0; lwz 0,0x8(28); addi 11,9,-2; addi 10,9,-1; rlwinm 11,11,2,0,29; rlwinm 9,9,2,0,29; add 11,11,0; add 9,9,0; lwz 31,-4(11); rlwinm 10,10,2,0,29; lwz 27,-4(9); add 10,10,0; lwz 9,0x0(31); lwz 29,-4(10); rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 8,9,5,31,31; 0:; cmpwi 8,0; beq 4f; lwz 0,0x0(29); li 11,0; rlwinm 9,0,0,25,31; cmpwi 9,7; bne 1f; rlwinm 11,0,5,31,31; 1:; cmpwi 11,0; bne 3f; cmpwi 9,6; li 9,0; bne 2f; rlwinm 9,0,5,31,31; 2:; cmpwi 9,0; beq 4f; 3:; mr 3,29; bl _s8027AFD0_0; mr 4,3; mr 5,27; mr 3,31; bl _s8027AFD0_1; b 17f; 4:; lwz 9,0x8(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 6f; lwz 9,0x0(31); li 10,0; rlwinm 11,9,0,25,31; addi 0,11,-12; cmplwi 0,7; bgt 5f; rlwinm 10,9,5,31,31; 5:; cmpwi 10,0; beq 14f; 6:; lis 11,-32700; addi 30,1,8; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); mr 3,29; addi 9,9,1; mr 4,30; sth 9,-6476(11); bl _s8027AFD0_2; lwz 5,0x8(26); mr 4,31; li 9,0; mr 6,30; mr 7,27; mr 3,28; li 8,1; li 10,1; bl _s8027AFD0_3; lis 9,-32694; lwz 3,0x8(1); lwz 4,-11332(9); lhz 5,0x2(3); lhz 0,0x2(4); cmpw 5,0; beq 7f; li 3,0; b 9f; 7:; cmpw 3,4; bne 8f; li 3,1; b 9f; 8:; addi 3,3,8; addi 4,4,8; bl _s8027AFD0_4; subfic 0,3,0; adde 3,0,3; 9:; cmpwi 3,0; beq 13f; lwz 9,0x0(31); li 0,0; rlwinm 11,9,0,25,31; cmpwi 11,27; bne 10f; rlwinm 0,9,5,31,31; 10:; cmpwi 0,0; bne 12f; addi 0,11,-12; li 11,0; cmplwi 0,7; bgt 11f; rlwinm 11,9,5,31,31; 11:; cmpwi 11,0; beq 13f; 12:; lwz 9,0x8(31); li 4,1; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; 13:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 17f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027AFD0_5; b 17f; 14:; cmpwi 11,11; li 0,0; bne 15f; rlwinm 0,9,5,31,31; 15:; cmpwi 0,0; beq 17f; lis 11,-32700; mr 3,27; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 4,1,8; addi 9,9,1; sth 9,-6476(11); bl _s8027AFD0_6; lwz 0,0x0(29); lis 9,-32694; addi 9,9,-16288; mr 3,29; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 16f; lwz 3,0x24(3); 16:; lwz 0,0x3c(9); lwz 3,0xc(3); lwz 4,0x8(1); mtspr 8,0; addi 3,3,8; addi 4,4,8; blrl; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 17f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027AFD0_7; 17:; lwz 0,0x0(28); cmpwi 0,3; blt 19f; li 30,1; lis 29,-32704; lis 31,-32704; 18:; lwz 11,0x0(28); addi 4,29,6004; lwz 8,0x8(28); addi 5,31,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,3; ble 18b; lwz 9,0x0(28); addi 9,9,-3; stw 9,0x0(28); 19:; lwz 3,-27600(13); lwz 0,0x4(3); cmpwi 0,0; beq 20f; lwz 0,0x0(28); cmpwi 0,0; bne 20f; bl _s8027AFD0_8; 20:; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"

extern "C" void _s8027AFD0_0();
extern "C" void _s8027AFD0_1();
extern "C" void _s8027AFD0_2();
extern "C" void _s8027AFD0_3();
extern "C" void _s8027AFD0_4();
extern "C" void _s8027AFD0_5();
extern "C" void _s8027AFD0_6();
extern "C" void _s8027AFD0_7();
extern "C" void _s8027AFD0_8();

struct AptActionInterpreter {
    void _FunctionAptActionSetMember_AptActionI();
};

void AptActionInterpreter::_FunctionAptActionSetMember_AptActionI() {
}
