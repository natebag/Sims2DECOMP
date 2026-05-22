// 0x802367B8 ERLevel::DrawOrderTable(void) (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 23,3; addis 31,23,3; lwz 0,-24188(31); cmpwi 0,0; beq 6f; lwz 25,-24008(31); mr 24,31; bl _s802367B8_0; lwz 4,-24188(31); li 5,0; mulli 4,4,12; bl _s802367B8_1; lwz 9,-24192(31); mr 26,3; mr 30,26; cmpwi 9,0; beq 1f; 0:; stw 9,0x0(30); lfs f0,0x2c(9); stfs f0,0x4(30); lfs f13,0x30(9); stfs f13,0x8(30); addi 30,30,12; lwz 9,0x28(9); cmpwi 9,0; bne 0b; 1:; lwz 4,-24188(24); lis 6,-32733; addi 6,6,17584; mr 3,26; li 5,12; lis 22,-32695; lis 27,17733; addi 29,22,-29652; bl _s802367B8_2; mr 30,26; ori 27,27,21062; mr 28,24; 2:; lwz 4,0x0(30); mr 3,23; mr 5,25; bl _s802367B8_3; lwz 31,0x0(30); li 0,0; lwz 11,-29652(22); cmplw 31,11; blt 3f; lwz 0,0xc(29); lwz 9,0x8(29); mullw 0,0,9; add 0,11,0; subfc 0,0,31; subfe 0,0,0; neg 0,0; 3:; cmpwi 0,0; beq 4f; cmpwi 31,0; beq 5f; stw 27,0x0(31); lwz 0,0x4(29); stw 0,0x4(31); stw 31,0x4(29); b 5f; 4:; bl _s802367B8_4; mr 4,31; bl _s802367B8_5; 5:; lwz 9,-24188(28); addi 30,30,12; addi 9,9,-1; cmpwi 9,0; stw 9,-24188(28); bgt 2b; li 0,0; stw 0,-24192(24); bl _s802367B8_6; mr 4,26; bl _s802367B8_7; lwz 11,0x70(25); lis 9,-32704; lfs f1,-2724(9); lha 3,0x258(11); lwz 0,0x25c(11); add 3,25,3; mtspr 8,0; blrl; 6:; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s802367B8_0();
extern "C" void _s802367B8_1();
extern "C" void _s802367B8_2();
extern "C" void _s802367B8_3();
extern "C" void _s802367B8_4();
extern "C" void _s802367B8_5();
extern "C" void _s802367B8_6();
extern "C" void _s802367B8_7();
extern "C" void f_802367B8() {}
