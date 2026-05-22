// 0x801949EC CASTarget::BroadcastNewFocus(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 31,3; bl _s801949EC_0; mr. 28,3; beq 0f; mr 4,28; mr 3,31; bl _s801949EC_1; lis 29,-32698; addi 30,1,8; lwz 11,0xa0(31); addi 29,29,28840; stw 29,0x4(30); li 0,2; stw 0,0x8(1); mr 4,30; lwz 9,0xa4(31); stw 3,0x8(30); addi 3,31,216; stw 28,0xc(30); stw 11,0x10(30); stw 9,0x14(30); bl _s801949EC_2; stw 29,0x4(30); mr 3,30; li 4,2; bl _s801949EC_3; 0:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s801949EC_0();
extern "C" void _s801949EC_1();
extern "C" void _s801949EC_2();
extern "C" void _s801949EC_3();
extern "C" void f_801949EC() {}
