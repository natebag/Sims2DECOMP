// 0x8026F8DC AptActionInterpreter::_doCloneSprite(AptCIH (628 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 25,0x34(1); stw 0,0x54(1); mr 3,4; li 0,0; mr 4,5; mr 30,7; mr 5,6; mr 25,9; stw 0,0x20(1); mr 26,8; addi 6,1,32; li 29,0; bl _s8026F8DC_0; lis 11,-32700; mr 3,30; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x18(1); addi 4,1,24; addi 9,9,1; sth 9,-6476(11); bl _s8026F8DC_1; lwz 30,0x20(1); cmpwi 30,0; beq 11f; lwz 9,0x48(30); cmpwi 9,0; beq 13f; lwz 9,0x4c(9); mr 3,30; lwz 28,0x4c(30); li 29,0; addi 27,9,36; li 31,0; bl _s8026F8DC_2; cmpwi 3,13; bne 0f; mr 3,30; bl _s8026F8DC_3; subfic 0,3,0; adde 31,0,3; 0:; cmpwi 31,0; bne 2f; mr 3,30; li 31,0; bl _s8026F8DC_4; cmpwi 3,18; bne 1f; mr 3,30; bl _s8026F8DC_5; subfic 0,3,0; adde 31,0,3; 1:; cmpwi 31,0; beq 3f; 2:; li 29,1; 3:; cmpwi 29,0; beq 4f; lwz 9,0x4c(30); lwz 29,0x20(9); b 5f; 4:; li 29,0; 5:; mr 3,30; li 31,0; bl _s8026F8DC_6; cmpwi 3,17; bne 6f; mr 3,30; bl _s8026F8DC_7; subfic 0,3,0; adde 31,0,3; 6:; cmpwi 31,0; beq 7f; lwz 9,0x4c(30); lfs f1,0x18(9); b 8f; 7:; lis 9,-32704; lfs f1,0x19b0(9); 8:; lwz 6,0x8(28); addi 9,30,16; lwz 8,0x48(30); addi 0,30,40; stw 9,0xc(1); mr 3,27; stw 29,0x10(1); li 9,1; stw 0,0x8(1); li 4,0; stw 25,0x14(1); mr 5,26; addi 7,1,24; li 10,-1; bl _s8026F8DC_8; lwz 9,0x4c(30); mr 29,3; lwz 31,0x2c(9); cmpwi 31,1; bne 10f; lwz 9,0x48(30); li 0,0; stw 0,0x24(1); mr 4,26; addi 5,1,24; addi 6,1,36; lwz 11,0x4c(9); addi 7,1,40; stw 0,0x28(1); lwz 3,0x24(11); bl _s8026F8DC_9; lwz 11,0x28(1); li 10,0; lwz 0,0x0(11); rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 9f; rlwinm 10,0,5,31,31; 9:; cmpwi 10,0; beq 10f; lwz 9,0x4c(11); stw 31,0x2c(9); 10:; lwz 3,-23008(13); bl _s8026F8DC_10; 11:; cmpwi 29,0; beq 13f; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 12f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F8DC_11; 12:; mr 3,29; b 15f; 13:; lwz 4,0x18(1); lwz 31,-22936(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 14f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F8DC_12; 14:; mr 3,31; 15:; lwz 0,0x54(1); mtspr 8,0; lmw 25,0x34(1); addi 1,1,80"

extern "C" void _s8026F8DC_0();
extern "C" void _s8026F8DC_1();
extern "C" void _s8026F8DC_2();
extern "C" void _s8026F8DC_3();
extern "C" void _s8026F8DC_4();
extern "C" void _s8026F8DC_5();
extern "C" void _s8026F8DC_6();
extern "C" void _s8026F8DC_7();
extern "C" void _s8026F8DC_8();
extern "C" void _s8026F8DC_9();
extern "C" void _s8026F8DC_10();
extern "C" void _s8026F8DC_11();
extern "C" void _s8026F8DC_12();

struct AptActionInterpreter {
    void _doCloneSprite_AptCIH();
};

void AptActionInterpreter::_doCloneSprite_AptCIH() {
}
