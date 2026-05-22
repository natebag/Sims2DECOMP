// 0x800A1F5C BString2::operator+=(BString2 (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 29,3; mr 3,31; bl _s800A1F5C_0; cmpwi 3,0; beq 0f; lwz 9,0x0(31); lwz 30,0x0(9); b 1f; 0:; li 30,0; 1:; mr 3,31; bl _s800A1F5C_1; mr 5,3; mr 4,30; mr 3,29; bl _s800A1F5C_2; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A1F5C_0();
extern "C" void _s800A1F5C_1();
extern "C" void _s800A1F5C_2();
extern "C" void f_800A1F5C() {}
