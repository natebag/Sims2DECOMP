// 0x800EE98C ObjectFolderImpl::ReconSelector(ObjSelector (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 24,0x18(1); stw 0,0x3c(1); stw 12,0x14(1); mr 26,3; mr 25,4; mr 31,5; cmpwi 7,46; ble 6f; cmpwi 6,0; beq 6f; lwz 30,0xc(31); cmpwi 30,0; beq 0f; lwz 9,0x0(25); mr 3,31; addi 4,1,8; li 5,1; lha 0,0x6c(9); sth 0,0x8(1); bl _s800EE98C_0; b 11f; 0:; mr 3,31; addi 4,1,8; li 5,1; bl _s800EE98C_1; lha 11,0x8(1); stw 30,0x0(25); cmpwi 11,0; blt 4f; lwz 0,0x674(26); lwz 9,0x670(26); subf 0,9,0; srawi 0,0,2; cmplw 11,0; bge 4f; rlwinm 11,11,2,0,29; addi 28,26,64; add 24,9,11; li 27,0; lwzx 9,9,11; rlwinm 9,9,2,22,29; lwzx 31,28,9; mr 29,9; b 2f; 1:; mr 27,31; lwz 31,0xa4(31); 2:; cmpwi 4,31,0; beq cr4,3f; lwz 30,0x0(24); mr 3,31; bl _s800EE98C_2; cmpw 30,3; bne 1b; cmpwi 27,0; beq 3f; lwz 0,0xa4(31); stw 0,0xa4(27); lwzx 9,28,29; stw 9,0xa4(31); stwx 31,28,29; 3:; beq cr4,4f; stw 31,0x0(25); 4:; lwz 0,0x0(25); cmpwi 0,0; bne 11f; addi 30,26,1664; lwz 3,0x680(26); lwz 4,0x4(30); addi 5,1,12; bl _s800EE98C_3; lwz 0,0x4(30); cmpw 3,0; beq 5f; lwz 9,0x0(26); lha 3,0x140(9); lwz 0,0x144(9); add 3,26,3; mtspr 8,0; blrl; b 10f; 5:; lwz 9,0x0(26); lis 4,15368; ori 4,4,38495; b 9f; 6:; lwz 0,0xc(31); cmpwi 0,1; beq 7f; cmpwi 0,2; bne 8f; 7:; lwz 3,0x0(25); bl _s800EE98C_4; stw 3,0xc(1); 8:; mr 3,31; addi 4,1,12; li 5,1; bl _s800EE98C_5; lwz 0,0xc(31); cmpwi 0,0; bne 11f; lwz 9,0x0(26); lwz 4,0xc(1); 9:; lha 3,0x78(9); lwz 0,0x7c(9); add 3,26,3; mtspr 8,0; blrl; 10:; stw 3,0x0(25); 11:; lwz 0,0x3c(1); lwz 12,0x14(1); mtspr 8,0; lmw 24,0x18(1); mtcrf 8,12; addi 1,1,56"
extern "C" void _s800EE98C_0();
extern "C" void _s800EE98C_1();
extern "C" void _s800EE98C_2();
extern "C" void _s800EE98C_3();
extern "C" void _s800EE98C_4();
extern "C" void _s800EE98C_5();
extern "C" void f_800EE98C() {}
