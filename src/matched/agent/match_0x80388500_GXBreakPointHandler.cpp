// 0x80388500 GXBreakPointHandler (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); li 0,0; stwu 1,-736(1); stw 31,0x2dc(1); addi 31,4,0; lwz 5,-17720(13); lwz 3,0x8(5); rlwimi 3,0,5,26,26; stw 3,0x8(5); lwz 0,0x8(5); lwz 3,-21996(13); sth 0,0x2(3); lwz 0,-21940(13); cmplwi 0,0; beq 0f; addi 3,1,16; bl _s80388500_0; addi 3,1,16; bl _s80388500_1; lwz 12,-21940(13); mtspr 8,12; blrl; addi 3,1,16; bl _s80388500_2; mr 3,31; bl _s80388500_3; 0:; lwz 0,0x2e4(1); lwz 31,0x2dc(1); addi 1,1,736; mtspr 8,0"
extern "C" void _s80388500_0();
extern "C" void _s80388500_1();
extern "C" void _s80388500_2();
extern "C" void _s80388500_3();
extern "C" void f_80388500() {}
