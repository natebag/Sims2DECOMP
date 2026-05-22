// 0x8022E788 EIStaticSubModel::BuildDigests(void) (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 30,3; li 27,0; lwz 0,0x7c(30); lwz 11,0xa0(30); mulli 0,0,24; lwz 9,0x3c(11); add 28,9,0; lwz 11,0x4(28); stw 11,0x9c(30); bl _s8022E788_0; lwz 4,0x9c(30); li 5,0; rlwinm 4,4,4,0,27; bl _s8022E788_1; lwz 9,0x9c(30); li 0,0; mr 31,3; stw 0,0x94(30); cmpw 27,9; stw 3,0x98(30); bge 1f; li 25,0; lis 26,-32692; li 29,0; 0:; lwz 9,0x0(28); li 5,0; li 6,0; addi 3,26,-17444; lwzx 11,9,29; addi 27,27,1; add 9,9,29; stw 11,0xc(31); addi 29,29,112; lhz 0,0xe(28); sth 25,0x2(31); sth 0,0x0(31); lwz 4,0xc(9); bl _s8022E788_2; stw 3,0x4(31); addi 4,30,8; mr 3,31; bl _s8022E788_3; addi 31,31,16; lwz 0,0x9c(30); cmpw 27,0; blt 0b; 1:; lwz 9,0xa0(30); lwz 0,0x24(9); cmpwi 0,0; beq 2f; li 0,0; stw 0,0x68(30); 2:; lwz 9,0xa0(30); lwz 0,0x28(9); cmpwi 0,0; beq 3f; li 0,0; stw 0,0x6c(30); 3:; lwz 9,0xa0(30); lwz 0,0x2c(9); cmpwi 0,0; beq 4f; li 0,0; stw 0,0x70(30); 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8022E788_0();
extern "C" void _s8022E788_1();
extern "C" void _s8022E788_2();
extern "C" void _s8022E788_3();
extern "C" void f_8022E788() {}
