// 0x8025C978 cbForUnrecoveredError (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,16; stw 0,0x4(1); stwu 1,-8(1); bne 0f; lis 3,291; addi 3,3,17768; bl _s8025C978_0; bl _s8025C978_1; li 3,0; bl _s8025C978_2; b 2f; 0:; rlwinm. 0,3,0,31,31; beq 1f; bl _s8025C978_3; b 2f; 1:; lis 3,-32730; addi 3,3,-13868; bl _s8025C978_4; 2:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025C978_0();
extern "C" void _s8025C978_1();
extern "C" void _s8025C978_2();
extern "C" void _s8025C978_3();
extern "C" void _s8025C978_4();
extern "C" void f_8025C978() {}
