// 0x8031B948 ERQuickdata::Load(EFile (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr 29,5; bl _s8031B948_0; lwz 4,0x14(31); mr 3,30; mr 6,29; addi 5,31,24; bl _s8031B948_1; cmpwi 3,0; stw 3,0x14(31); beq 0f; lwz 0,0x10(31); lwz 9,0x18(31); rlwimi 0,9,8,0,23; stw 0,0x10(31); 0:; mr 3,31; bl _s8031B948_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8031B948_0();
extern "C" void _s8031B948_1();
extern "C" void _s8031B948_2();
extern "C" void f_8031B948() {}
