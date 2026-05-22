// 0x80375B04 __ARHandler (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-13312; stw 0,0x4(1); addi 3,3,20480; li 0,-137; stwu 1,-736(1); stw 31,0x2dc(1); addi 31,4,0; lhz 5,0xa(3); and 0,5,0; ori 0,0,32; sth 0,0xa(3); addi 3,1,16; bl _s80375B04_0; addi 3,1,16; bl _s80375B04_1; lwz 12,-22368(13); cmplwi 12,0; beq 0f; mtspr 8,12; blrl; 0:; addi 3,1,16; bl _s80375B04_2; mr 3,31; bl _s80375B04_3; lwz 0,0x2e4(1); lwz 31,0x2dc(1); addi 1,1,736; mtspr 8,0"
extern "C" void _s80375B04_0();
extern "C" void _s80375B04_1();
extern "C" void _s80375B04_2();
extern "C" void _s80375B04_3();
extern "C" void f_80375B04() {}
