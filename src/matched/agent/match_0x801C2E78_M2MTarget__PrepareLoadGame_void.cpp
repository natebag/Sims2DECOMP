// 0x801C2E78 M2MTarget::PrepareLoadGame(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,1; lwz 3,-32056(13); stw 30,0x180(31); bl _s801C2E78_0; lis 9,-32697; li 0,0; addi 9,9,24012; mr 3,31; stw 0,0x44c(9); stw 0,0x448(9); bl _s801C2E78_1; cmpwi 3,0; beq 0f; li 0,9; stw 30,0x168(31); stw 0,0x11c(31); b 1f; 0:; li 0,8; mr 3,31; stw 0,0x11c(31); bl _s801C2E78_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801C2E78_0();
extern "C" void _s801C2E78_1();
extern "C" void _s801C2E78_2();
extern "C" void f_801C2E78() {}
