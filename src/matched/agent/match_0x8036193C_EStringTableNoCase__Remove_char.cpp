// 0x8036193C EStringTableNoCase::Remove(char (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; bl _s8036193C_0; mr 29,3; mr 5,30; mr 3,31; mr 4,29; bl _s8036193C_1; mr. 5,3; li 3,0; beq 0f; mr 3,31; mr 4,29; bl _s8036193C_2; li 3,1; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8036193C_0();
extern "C" void _s8036193C_1();
extern "C" void _s8036193C_2();
extern "C" void f_8036193C() {}
