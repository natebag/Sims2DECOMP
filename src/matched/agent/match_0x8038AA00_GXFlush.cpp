// 0x8038AA00 GXFlush (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 3,-17720(13); lwz 0,0x5ac(3); cmplwi 0,0; beq 0f; bl _s8038AA00_0; 0:; li 0,0; lis 3,-13311; stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); bl _s8038AA00_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8038AA00_0();
extern "C" void _s8038AA00_1();
extern "C" void f_8038AA00() {}
