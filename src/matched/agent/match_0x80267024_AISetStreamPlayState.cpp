// 0x80267024 AISetStreamPlayState (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; bl _s80267024_0; cmplw 29,3; beq 1f; bl _s80267024_1; cmplwi 3,0; bne 0f; cmplwi 29,1; bne 0f; bl _s80267024_2; mr 30,3; bl _s80267024_3; addi 29,3,0; li 3,0; bl _s80267024_4; li 3,0; bl _s80267024_5; bl _s80267024_6; mr 31,3; bl _s80267024_7; lis 4,-13312; lwz 0,0x6c00(4); addi 3,31,0; rlwinm 0,0,0,27,25; ori 0,0,32; stw 0,0x6c00(4); lwz 0,0x6c00(4); rlwinm 0,0,0,0,30; ori 0,0,1; stw 0,0x6c00(4); bl _s80267024_8; mr 3,30; bl _s80267024_9; mr 3,29; bl _s80267024_10; b 1f; 0:; lis 3,-13312; lwz 0,0x6c00(3); rlwinm 0,0,0,0,30; or 0,0,29; stw 0,0x6c00(3); 1:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80267024_0();
extern "C" void _s80267024_1();
extern "C" void _s80267024_2();
extern "C" void _s80267024_3();
extern "C" void _s80267024_4();
extern "C" void _s80267024_5();
extern "C" void _s80267024_6();
extern "C" void _s80267024_7();
extern "C" void _s80267024_8();
extern "C" void _s80267024_9();
extern "C" void _s80267024_10();
extern "C" void f_80267024() {}
