// 0x80261098 Read (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); li 0,0; stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); addi 30,5,0; stw 29,0x1c(1); addi 29,4,0; stw 28,0x18(1); addi 28,3,0; stw 0,-23360(13); li 0,1; stw 6,-23352(13); lis 6,-32694; addi 31,6,-16952; stw 0,-23296(13); bl _s80261098_0; stw 4,-23300(13); lis 4,-13312; lis 0,160; stw 3,-23304(13); addi 4,4,24576; lis 3,-22528; stw 3,0x8(4); rlwinm 3,30,30,2,31; cmplw 29,0; stw 3,0xc(4); li 0,3; stw 29,0x10(4); stw 28,0x14(4); stw 29,0x18(4); stw 29,-23356(13); stw 0,0x1c(4); ble 0f; lis 3,-32768; lwz 0,0xf8(3); addi 3,31,104; rlwinm 0,0,30,2,31; mulli 30,0,20; bl _s80261098_1; lis 3,-32730; addi 7,3,4036; addi 6,30,0; addi 3,31,104; li 5,0; bl _s80261098_2; b 1f; 0:; lis 3,-32768; lwz 0,0xf8(3); addi 3,31,104; rlwinm 0,0,30,2,31; mulli 30,0,10; bl _s80261098_3; lis 3,-32730; addi 7,3,4036; addi 6,30,0; addi 3,31,104; li 5,0; bl _s80261098_4; 1:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80261098_0();
extern "C" void _s80261098_1();
extern "C" void _s80261098_2();
extern "C" void _s80261098_3();
extern "C" void _s80261098_4();
extern "C" void f_80261098() {}
