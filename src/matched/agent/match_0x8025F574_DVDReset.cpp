// 0x8025F574 DVDReset (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8025F574_0; lis 3,-13312; li 0,42; stw 0,0x6000(3); addi 4,3,24576; li 0,0; lwz 3,0x6004(3); stw 3,0x4(4); stw 0,-23424(13); stw 0,-23440(13); lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025F574_0();
extern "C" void f_8025F574() {}
