// 0x8025C9D4 cbForUnrecoveredErrorRetry (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,16; stw 0,0x4(1); stwu 1,-8(1); bne 0f; lis 3,291; addi 3,3,17768; bl _s8025C9D4_0; bl _s8025C9D4_1; li 3,0; bl _s8025C9D4_2; b 2f; 0:; rlwinm. 0,3,0,30,30; beq 1f; lis 3,291; addi 3,3,17767; bl _s8025C9D4_3; lis 3,-32730; addi 3,3,-15216; bl _s8025C9D4_4; b 2f; 1:; lis 3,-13312; addi 3,3,24576; lwz 3,0x20(3); bl _s8025C9D4_5; lis 3,-32730; addi 3,3,-15216; bl _s8025C9D4_6; 2:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025C9D4_0();
extern "C" void _s8025C9D4_1();
extern "C" void _s8025C9D4_2();
extern "C" void _s8025C9D4_3();
extern "C" void _s8025C9D4_4();
extern "C" void _s8025C9D4_5();
extern "C" void _s8025C9D4_6();
extern "C" void f_8025C9D4() {}
