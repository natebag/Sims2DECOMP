// 0x80176D6C UI3D::InstallEntry(char (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; mr 27,4; lwz 0,0x8(31); mr 30,5; mr 29,6; mr 28,7; mr 25,8; mr 26,9; cmpwi 0,0; beq 2f; bl _s80176D6C_0; mr. 3,3; beq 1f; lwz 0,0x14(3); cmpw 0,28; bne 0f; lwz 0,0xc(3); cmpw 0,30; bne 0f; lwz 0,0x10(3); cmpw 0,29; bne 0f; lwz 3,0x1c(3); mr 4,26; bl _s80176D6C_1; li 3,1; b 3f; 0:; mr 4,3; mr 3,31; bl _s80176D6C_2; 1:; mr 3,31; mr 4,27; mr 5,30; mr 6,29; mr 7,28; mr 8,26; mr 9,25; bl _s80176D6C_3; li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s80176D6C_0();
extern "C" void _s80176D6C_1();
extern "C" void _s80176D6C_2();
extern "C" void _s80176D6C_3();
extern "C" void f_80176D6C() {}
