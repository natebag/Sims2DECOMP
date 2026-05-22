// 0x801ECCC0 StaticNumberToWideString(int, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 30,3; mr. 31,4; beq 0f; addi 29,1,8; li 4,0; li 5,32; mr 3,29; crxor 6,6,6; bl _s801ECCC0_0; lis 4,-32704; mr 5,30; addi 4,4,-30836; mr 3,29; crxor 6,6,6; bl _s801ECCC0_1; mr 30,3; mr 5,31; mr 4,30; mr 3,29; bl _s801ECCC0_2; li 0,0; add 30,30,30; sthx 0,30,31; mr 3,31; bl _s801ECCC0_3; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s801ECCC0_0();
extern "C" void _s801ECCC0_1();
extern "C" void _s801ECCC0_2();
extern "C" void _s801ECCC0_3();
extern "C" void f_801ECCC0() {}
