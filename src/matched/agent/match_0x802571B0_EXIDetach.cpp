// 0x802571B0 EXIDetach (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); addi 29,3,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 31,0,4; bl _s802571B0_0; mr 30,3; lwz 0,0xc(31); rlwinm. 0,0,0,28,28; bne 0f; mr 3,30; bl _s802571B0_1; li 3,1; b 2f; 0:; lwz 0,0xc(31); rlwinm. 0,0,0,27,27; beq 1f; lwz 0,0x18(31); cmplwi 0,0; bne 1f; mr 3,30; bl _s802571B0_2; li 3,0; b 2f; 1:; lwz 0,0xc(31); rlwinm 0,0,0,29,27; stw 0,0xc(31); lis 3,80; mulli 0,29,3; srw 3,3,0; bl _s802571B0_3; mr 3,30; bl _s802571B0_4; li 3,1; 2:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802571B0_0();
extern "C" void _s802571B0_1();
extern "C" void _s802571B0_2();
extern "C" void _s802571B0_3();
extern "C" void _s802571B0_4();
extern "C" void f_802571B0() {}
