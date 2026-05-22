// 0x800EED2C ObjectFolderImpl::ReconBehavior(Behavior (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 25,0x14(1); stw 0,0x34(1); stw 12,0x10(1); mr 31,3; mr 25,4; mr 3,5; cmpwi 6,46; ble 5f; lwz 30,0xc(3); cmpwi 30,0; beq 1f; lwz 9,0x0(25); li 11,0; lwz 4,0x8(9); cmpwi 4,0; beq 0f; lwz 11,0x4(4); 0:; lha 0,0x6c(11); addi 4,1,8; li 5,1; sth 0,0x8(1); bl _s800EED2C_0; b 7f; 1:; addi 4,1,8; li 5,1; bl _s800EED2C_1; lhz 10,0x8(1); stw 30,0x0(25); extsh 11,10; cmpwi 11,0; blt 7f; lwz 0,0x674(31); lwz 9,0x670(31); subf 0,9,0; srawi 0,0,2; cmplw 10,0; bge 7f; rlwinm 11,11,2,0,29; addi 28,31,64; add 26,9,11; li 27,0; lwzx 9,9,11; rlwinm 9,9,2,22,29; lwzx 31,28,9; mr 29,9; b 3f; 2:; mr 27,31; lwz 31,0xa4(31); 3:; cmpwi 4,31,0; beq cr4,4f; lwz 30,0x0(26); mr 3,31; bl _s800EED2C_2; cmpw 30,3; bne 2b; cmpwi 27,0; beq 4f; lwz 0,0xa4(31); stw 0,0xa4(27); lwzx 9,28,29; stw 9,0xa4(31); stwx 31,28,29; 4:; beq cr4,7f; lwz 0,0xc(31); stw 0,0x0(25); b 7f; 5:; addi 4,1,12; li 5,1; bl _s800EED2C_3; lwz 9,0x0(31); lwz 4,0xc(1); lha 3,0x78(9); lwz 0,0x7c(9); add 3,31,3; mtspr 8,0; blrl; mr. 3,3; beq 6f; lwz 0,0xc(3); stw 0,0x0(25); b 7f; 6:; stw 3,0x0(25); 7:; lwz 0,0x34(1); lwz 12,0x10(1); mtspr 8,0; lmw 25,0x14(1); mtcrf 8,12; addi 1,1,48"
extern "C" void _s800EED2C_0();
extern "C" void _s800EED2C_1();
extern "C" void _s800EED2C_2();
extern "C" void _s800EED2C_3();
extern "C" void f_800EED2C() {}
