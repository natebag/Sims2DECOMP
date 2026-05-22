// 0x80095780 TheSimsStartScreenStateMachine::Startup(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 3,56; bl _s80095780_0; mr 30,3; bl _s80095780_1; stw 30,-24644(13); li 3,36; bl _s80095780_2; lis 11,-32698; mr 9,3; li 0,0; li 8,-1; addi 11,11,-8080; li 10,1; mr 4,9; stw 8,0xc(9); stw 10,0x14(9); mr 3,29; stw 11,0x18(9); stw 0,0x20(9); stw 0,0x0(9); stw 8,0x4(9); stw 0,0x8(9); stw 0,0x10(9); stw 0,0x1c(9); bl _s80095780_3; lis 3,-32693; lis 4,-32706; addi 4,4,-30756; addi 3,3,24536; bl _s80095780_4; bl _s80095780_5; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80095780_0();
extern "C" void _s80095780_1();
extern "C" void _s80095780_2();
extern "C" void _s80095780_3();
extern "C" void _s80095780_4();
extern "C" void _s80095780_5();
extern "C" void f_80095780() {}
