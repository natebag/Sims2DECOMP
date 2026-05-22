// 0x8029CE2C AptAnimationPoolData::_doButtonActions(AptCIH (472 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 27,4; li 26,0; lwz 9,0x4c(27); mr 23,3; mr 25,5; lwz 24,0x8(9); lwz 0,0x34(24); cmpw 26,0; bge 2f; li 31,0; 0:; lwz 9,0x38(24); lwzx 0,31,9; add 30,31,9; and. 9,0,25; beq 1f; addi 30,30,4; lwz 29,0x48(27); lwz 28,-27612(13); mr 3,23; bl _s8029CE2C_0; mr 4,30; mr 5,29; mr 6,28; bl _s8029CE2C_1; 1:; lwz 0,0x34(24); addi 26,26,1; addi 31,31,8; cmpw 26,0; blt 0b; 2:; mr 3,25; bl _s8029CE2C_2; lwz 9,0x8(27); mr 31,3; lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,27,3; blrl; lwz 0,0x10(3); and. 9,0,31; beq 5f; lis 9,-32700; lis 11,-32694; addi 28,9,-9844; addi 22,11,-11332; addi 26,28,72; 3:; lwz 0,0x0(28); and. 9,31,0; beq 4f; mr 3,27; bl _s8029CE2C_3; lwz 4,0x4(28); rlwinm 4,4,2,0,29; add 4,4,22; bl _s8029CE2C_4; mr. 29,3; beq 4f; lwz 30,0x8(28); lwz 3,-23008(13); rlwinm 30,30,10,15,21; ori 30,30,5; bl _s8029CE2C_5; mr 5,29; mr 7,30; mr 4,27; li 6,0; bl _s8029CE2C_6; 4:; addi 28,28,12; cmpw 28,26; ble 3b; 5:; lwz 9,0x3c(24); cmpwi 9,0; beq 12f; cmpwi 25,2; beq 7f; bgt 6f; cmpwi 25,1; beq 8f; b 12f; 6:; cmpwi 25,4; beq 9f; cmpwi 25,8; beq 11f; b 12f; 7:; lwz 11,0x0(9); b 10f; 8:; lwz 11,0x4(9); b 10f; 9:; lwz 11,0x8(9); 10:; cmpwi 11,0; beq 12f; lis 9,-32694; lwz 3,0x8(11); lwz 0,-16196(9); li 4,0; mtspr 8,0; blrl; b 12f; 11:; lwz 11,0xc(9); cmpwi 11,0; beq 12f; lis 9,-32694; lwz 3,0x8(11); lwz 0,-16196(9); li 4,0; mtspr 8,0; blrl; 12:; mr 3,23; bl _s8029CE2C_7; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s8029CE2C_0();
extern "C" void _s8029CE2C_1();
extern "C" void _s8029CE2C_2();
extern "C" void _s8029CE2C_3();
extern "C" void _s8029CE2C_4();
extern "C" void _s8029CE2C_5();
extern "C" void _s8029CE2C_6();
extern "C" void _s8029CE2C_7();
extern "C" void f_8029CE2C() {}
