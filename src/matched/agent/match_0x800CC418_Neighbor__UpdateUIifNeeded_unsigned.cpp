// 0x800CC418 Neighbor::UpdateUIifNeeded(unsigned (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 27,4; rlwinm 0,27,2,0,29; addi 9,31,408; lwzx 29,9,0; mr 26,5; cmpwi 29,0; beq 2f; lwz 11,0x18(31); cmpwi 11,0; beq 2f; lis 9,-32697; lwz 0,0x5bcc(9); cmpwi 0,0; beq 2f; lis 9,-32697; addi 9,9,24012; lwz 0,0xbc(9); cmpw 11,0; bne 0f; li 28,0; b 1f; 0:; lwz 0,0xc0(9); cmpw 11,0; bne 2f; li 28,1; 1:; mr 4,31; mr 3,29; bl _s800CC418_0; mr 30,3; mr 4,31; mr 3,29; bl _s800CC418_1; lis 9,-32697; mr 7,3; lwz 3,0x5bcc(9); mr 4,28; mr 5,27; mr 6,30; mr 8,26; mr 9,31; bl _s800CC418_2; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800CC418_0();
extern "C" void _s800CC418_1();
extern "C" void _s800CC418_2();
extern "C" void f_800CC418() {}
