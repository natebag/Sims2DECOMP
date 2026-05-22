// 0x803799A4 __AXOutQuit (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s803799A4_0; li 0,0; lis 4,-32690; stw 0,-22176(13); addi 0,4,29024; addi 31,3,0; mr 3,0; bl _s803799A4_1; addi 3,13,-22160; bl _s803799A4_2; bl _s803799A4_3; mr 3,31; bl _s803799A4_4; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s803799A4_0();
extern "C" void _s803799A4_1();
extern "C" void _s803799A4_2();
extern "C" void _s803799A4_3();
extern "C" void _s803799A4_4();
extern "C" void f_803799A4() {}
