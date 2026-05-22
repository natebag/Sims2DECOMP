// 0x803351D8 ENgcMovie::~ENgcMovie(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 31,3; addi 9,9,-14024; mr 29,4; stw 9,0x8(31); bl _s803351D8_0; addi 30,31,68; mr 3,30; bl _s803351D8_1; mr 3,30; bl _s803351D8_2; lis 9,-32697; andi. 0,29,1; addi 9,9,-9664; stw 9,0x8(31); beq 0f; mr 3,31; bl _s803351D8_3; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803351D8_0();
extern "C" void _s803351D8_1();
extern "C" void _s803351D8_2();
extern "C" void _s803351D8_3();
extern "C" void f_803351D8() {}
