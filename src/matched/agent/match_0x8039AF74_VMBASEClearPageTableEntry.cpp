// 0x8039AF74 VMBASEClearPageTableEntry (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); stw 31,0x1c(1); stw 30,0x18(1); mr 30,4; stw 29,0x14(1); mr 29,3; bl _s8039AF74_0; mr 0,3; mr 3,29; mr 31,0; bl _s8039AF74_1; li 0,0; li 4,8; stw 0,0x0(3); stw 0,0x4(3); bl _s8039AF74_2; mr 3,29; bl _s8039AF74_3; mr 3,30; li 4,0; bl _s8039AF74_4; mr 3,30; li 4,0; bl _s8039AF74_5; mr 3,31; bl _s8039AF74_6; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s8039AF74_0();
extern "C" void _s8039AF74_1();
extern "C" void _s8039AF74_2();
extern "C" void _s8039AF74_3();
extern "C" void _s8039AF74_4();
extern "C" void _s8039AF74_5();
extern "C" void _s8039AF74_6();
extern "C" void f_8039AF74() {}
