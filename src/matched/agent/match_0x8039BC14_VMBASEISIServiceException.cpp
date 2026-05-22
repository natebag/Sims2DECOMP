// 0x8039BC14 __VMBASEISIServiceException (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-736(1); mfspr 0,8; stw 0,0x2e4(1); stw 31,0x2dc(1); mr 31,3; addi 3,1,8; bl _s8039BC14_0; addi 3,1,8; bl _s8039BC14_1; lwz 12,-21524(13); lwz 3,0x198(31); mtspr 9,12; bctrl; mr 3,31; bl _s8039BC14_2; mr 3,31; bl _s8039BC14_3; lwz 0,0x2e4(1); lwz 31,0x2dc(1); mtspr 8,0; addi 1,1,736"
extern "C" void _s8039BC14_0();
extern "C" void _s8039BC14_1();
extern "C" void _s8039BC14_2();
extern "C" void _s8039BC14_3();
extern "C" void f_8039BC14() {}
