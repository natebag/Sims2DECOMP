// 0x8029BF98 AptDisplayList::validate(AptCIH (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 11,0x0(3); mr 28,4; lwz 9,0x0(11); lwz 31,0x54(9); cmpwi 31,0; beq 13f; lis 9,-32700; addi 27,9,-6476; 0:; lwz 29,0x48(31); cmpwi 28,0; beq 7f; lwz 0,0xc(31); cmpw 0,27; beq 7f; lwz 0,0x0(31); andis. 9,0,2048; beq 7f; lwz 9,0x4c(29); lwz 3,0xc(9); bl _s8029BF98_0; mr. 30,3; beq 7f; 1:; lwz 11,0x4(30); li 10,0; lwz 0,0x0(11); rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 2f; rlwinm 10,0,5,31,31; 2:; cmpwi 10,0; beq 6f; cmpw 11,31; beq 7f; lwz 3,0x0(30); lwz 4,0xc(31); lhz 5,0x2(3); lhz 0,0x2(4); cmpw 5,0; beq 3f; li 3,0; b 5f; 3:; cmpw 3,4; bne 4f; li 3,1; b 5f; 4:; addi 3,3,8; addi 4,4,8; bl _s8029BF98_1; subfic 0,3,0; adde 3,0,3; 5:; cmpwi 3,0; bne 7f; 6:; lwz 9,0x4c(29); mr 4,30; lwz 3,0xc(9); bl _s8029BF98_2; mr. 30,3; bne 1b; 7:; mr 3,31; li 29,0; bl _s8029BF98_3; li 30,0; cmpwi 3,13; bne 8f; mr 3,31; bl _s8029BF98_4; subfic 0,3,0; adde 30,0,3; 8:; cmpwi 30,0; bne 10f; mr 3,31; li 30,0; bl _s8029BF98_5; cmpwi 3,18; bne 9f; mr 3,31; bl _s8029BF98_6; subfic 0,3,0; adde 30,0,3; 9:; cmpwi 30,0; beq 11f; 10:; li 29,1; 11:; cmpwi 29,0; beq 12f; lwz 3,0x4c(31); mr 4,31; addi 3,3,36; bl _s8029BF98_7; 12:; lwz 31,0x54(31); cmpwi 31,0; bne 0b; 13:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8029BF98_0();
extern "C" void _s8029BF98_1();
extern "C" void _s8029BF98_2();
extern "C" void _s8029BF98_3();
extern "C" void _s8029BF98_4();
extern "C" void _s8029BF98_5();
extern "C" void _s8029BF98_6();
extern "C" void _s8029BF98_7();

struct AptDisplayList {
    void validate_AptCIH();
};

void AptDisplayList::validate_AptCIH() {
}
