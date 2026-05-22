// 0x8025D1B0 cbForStateCoverClosed (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,16; stw 0,0x4(1); stwu 1,-8(1); bne 0f; lis 3,291; addi 3,3,17768; bl _s8025D1B0_0; bl _s8025D1B0_1; li 3,0; bl _s8025D1B0_2; b 2f; 0:; rlwinm. 0,3,0,31,31; beq 1f; li 0,0; stw 0,-23428(13); bl _s8025D1B0_3; b 2f; 1:; lis 3,-32730; addi 3,3,-14572; bl _s8025D1B0_4; 2:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025D1B0_0();
extern "C" void _s8025D1B0_1();
extern "C" void _s8025D1B0_2();
extern "C" void _s8025D1B0_3();
extern "C" void _s8025D1B0_4();
extern "C" void f_8025D1B0() {}
