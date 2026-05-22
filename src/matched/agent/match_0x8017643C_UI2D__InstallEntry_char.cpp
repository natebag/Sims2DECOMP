// 0x8017643C UI2D::InstallEntry(char (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 30,4; mr 28,6; mr 27,7; mr. 29,5; beq 1f; lwz 0,0x8(31); cmpwi 0,0; beq 1f; mr 3,31; mr 4,30; bl _s8017643C_0; mr. 3,3; beq 0f; mr 4,3; mr 3,31; bl _s8017643C_1; 0:; mr 3,31; mr 4,30; mr 6,29; mr 7,28; mr 8,27; li 5,0; bl _s8017643C_2; li 3,1; b 2f; 1:; li 3,0; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8017643C_0();
extern "C" void _s8017643C_1();
extern "C" void _s8017643C_2();
extern "C" void f_8017643C() {}
