// 0x80261848 DVDLowRequestError (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); li 0,0; stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); stw 3,-23352(13); lis 3,-13312; addi 4,3,24576; stw 0,-23360(13); lis 0,-8192; stw 0,0x6008(3); li 0,1; lis 3,-32694; stw 0,0x1c(4); lis 4,-32768; addi 31,3,-16848; lwz 0,0xf8(4); addi 3,31,0; rlwinm 0,0,30,2,31; mulli 30,0,10; bl _s80261848_0; lis 3,-32730; addi 7,3,4036; addi 3,31,0; addi 6,30,0; li 5,0; bl _s80261848_1; lwz 0,0x1c(1); li 3,1; lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80261848_0();
extern "C" void _s80261848_1();
extern "C" void f_80261848() {}
