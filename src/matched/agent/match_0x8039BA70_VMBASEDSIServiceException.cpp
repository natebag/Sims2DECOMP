// 0x8039BA70 __VMBASEDSIServiceException (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-736(1); mfspr 0,8; stw 0,0x2e4(1); stw 31,0x2dc(1); mr 31,4; stw 30,0x2d8(1); mr 30,3; addi 3,1,8; bl _s8039BA70_0; addi 3,1,8; bl _s8039BA70_1; lwz 12,-21524(13); mr 3,31; mtspr 9,12; bctrl; mr 3,30; bl _s8039BA70_2; mr 3,30; bl _s8039BA70_3; lwz 0,0x2e4(1); lwz 31,0x2dc(1); lwz 30,0x2d8(1); mtspr 8,0; addi 1,1,736"
extern "C" void _s8039BA70_0();
extern "C" void _s8039BA70_1();
extern "C" void _s8039BA70_2();
extern "C" void _s8039BA70_3();
extern "C" void f_8039BA70() {}
