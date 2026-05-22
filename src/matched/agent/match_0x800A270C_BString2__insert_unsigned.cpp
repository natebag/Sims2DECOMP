// 0x800A270C BString2::insert(unsigned (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; mr. 31,5; beq 0f; mr 3,31; bl _s800A270C_0; b 1f; 0:; li 3,0; 1:; mr 6,3; mr 4,30; mr 3,29; mr 5,31; bl _s800A270C_1; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A270C_0();
extern "C" void _s800A270C_1();
extern "C" void f_800A270C() {}
