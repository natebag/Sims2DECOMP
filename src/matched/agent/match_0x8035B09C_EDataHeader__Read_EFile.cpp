// 0x8035B09C EDataHeader::Read(EFile (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 24,0x30(1); stw 0,0x54(1); mr 30,4; mr 29,3; lwz 9,0x28(30); mr 24,6; stw 5,0x28(1); mr 25,7; li 28,0; li 26,0; lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; blrl; mr 27,3; 0:; mr 3,29; addi 28,28,1; bl _s8035B09C_0; lwz 9,0x28(30); mr 4,27; li 5,0; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); addi 4,1,8; li 5,16; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0xc(1); lwz 9,0x28(1); lwz 10,0x8(1); lwz 0,0x10(1); cmpw 11,9; lwz 31,0x14(1); stw 0,0xc(29); stw 10,0x4(29); stw 11,0x8(29); beq 2f; li 0,4; addi 5,1,24; mtspr 9,0; addi 6,1,32; cmpwi 28,3; mr 4,5; mr 7,6; li 10,0; lis 3,-32702; mfcr 31; addi 8,1,40; addi 11,29,8; 1:; lbzx 0,10,8; lbz 9,0x0(11); stbx 0,4,10; addi 11,11,1; stbx 9,7,10; addi 10,10,1; bdnz 1b; stbx 26,5,10; addi 3,3,11476; stbx 26,6,10; mr 4,28; crxor 6,6,6; bl _s8035B09C_1; mtcrf 128,31; ble 8f; b 9f; 2:; cmplw 10,25; ble 3f; lis 3,-32702; mr 4,28; addi 3,3,11528; crxor 6,6,6; bl _s8035B09C_2; b 4f; 3:; cmplw 10,24; bge 5f; 4:; cmpwi 28,3; ble 8f; b 9f; 5:; cmpwi 31,0; bne 6f; stw 31,0x0(29); b 7f; 6:; bl _s8035B09C_3; mr 4,31; li 5,0; bl _s8035B09C_4; mr 4,3; mr 5,31; stw 4,0x0(29); lwz 9,0x28(30); lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; 7:; lwz 9,0x28(30); addi 4,29,16; li 5,4; lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; li 3,1; b 10f; 8:; addi 28,28,1; cmpwi 28,3; ble 0b; 9:; mr 3,29; bl _s8035B09C_5; lwz 9,0x28(30); mr 4,27; li 5,0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,30,3; mtspr 8,0; blrl; li 3,0; 10:; lwz 0,0x54(1); mtspr 8,0; lmw 24,0x30(1); addi 1,1,80"
extern "C" void _s8035B09C_0();
extern "C" void _s8035B09C_1();
extern "C" void _s8035B09C_2();
extern "C" void _s8035B09C_3();
extern "C" void _s8035B09C_4();
extern "C" void _s8035B09C_5();
extern "C" void f_8035B09C() {}
