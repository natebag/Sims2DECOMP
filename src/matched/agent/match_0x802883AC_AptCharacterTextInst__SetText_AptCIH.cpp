// 0x802883AC AptCharacterTextInst::SetText(AptCIH (852 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 28,3; lis 9,-32700; lwz 11,0x1c(28); addi 9,9,-6476; cmpw 11,9; beq 18f; lbz 0,0x8(11); cmpwi 0,36; bne 1f; lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x18(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802883AC_0; 0:; lwz 0,0x1c(28); stw 0,0x18(28); b 18f; 1:; mr. 29,4; addi 27,28,28; beq 7f; 2:; mr 3,29; li 30,0; bl _s802883AC_1; li 31,0; cmpwi 3,13; bne 3f; mr 3,29; bl _s802883AC_2; subfic 0,3,0; adde 31,0,3; 3:; cmpwi 31,0; bne 5f; mr 3,29; li 31,0; bl _s802883AC_3; cmpwi 3,18; bne 4f; mr 3,29; bl _s802883AC_4; subfic 0,3,0; adde 31,0,3; 4:; cmpwi 31,0; beq 6f; 5:; li 30,1; 6:; cmpwi 30,0; bne 7f; lwz 0,0x48(29); cmpwi 0,0; beq 7f; mr 29,0; b 2b; 7:; lis 3,-32694; li 9,0; mr 4,29; addi 3,3,-16032; li 5,0; mr 6,27; li 7,1; li 8,1; bl _s802883AC_5; lwz 0,0x0(3); andis. 9,0,2048; bne 17f; lwz 31,-26892(13); cmpwi 31,0; beq 10f; lwz 0,0x0(31); lwz 9,0x10(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 8f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 9f; 8:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 9:; addi 30,31,12; mr 3,30; bl _s802883AC_6; cmpwi 3,0; bne 11f; mr 3,30; li 4,0; bl _s802883AC_7; b 11f; 10:; lwz 3,-23020(13); li 4,20; bl _s802883AC_8; bl _s802883AC_9; mr 31,3; 11:; lwz 9,0x8(28); lwz 4,0x34(9); cmpwi 4,0; beq 13f; addi 3,1,8; bl _s802883AC_10; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 12f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802883AC_11; 12:; lwz 0,0x8(1); stw 0,0xc(31); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 15f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802883AC_12; b 15f; 13:; lis 4,-32704; addi 3,1,8; addi 4,4,18440; bl _s802883AC_13; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 14f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802883AC_14; 14:; lwz 0,0x8(1); stw 0,0xc(31); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 15f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802883AC_15; 15:; lwz 11,0xc(31); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x18(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 16f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802883AC_16; 16:; lwz 0,0xc(31); lis 3,-32694; addi 3,3,-16032; mr 4,29; stw 0,0x18(28); mr 6,27; mr 7,31; li 5,0; li 8,1; li 9,1; li 10,0; bl _s802883AC_17; b 18f; 17:; addi 4,28,24; bl _s802883AC_18; 18:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s802883AC_0();
extern "C" void _s802883AC_1();
extern "C" void _s802883AC_2();
extern "C" void _s802883AC_3();
extern "C" void _s802883AC_4();
extern "C" void _s802883AC_5();
extern "C" void _s802883AC_6();
extern "C" void _s802883AC_7();
extern "C" void _s802883AC_8();
extern "C" void _s802883AC_9();
extern "C" void _s802883AC_10();
extern "C" void _s802883AC_11();
extern "C" void _s802883AC_12();
extern "C" void _s802883AC_13();
extern "C" void _s802883AC_14();
extern "C" void _s802883AC_15();
extern "C" void _s802883AC_16();
extern "C" void _s802883AC_17();
extern "C" void _s802883AC_18();
extern "C" void f_802883AC() {}
