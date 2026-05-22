// 0x80260A24 __fstLoad (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32700; stw 0,0x4(1); stwu 1,-96(1); stw 31,0x5c(1); addi 31,3,-12808; stw 30,0x58(1); stw 29,0x54(1); bl _s80260A24_0; lis 3,-32694; addi 3,3,-17064; addi 4,1,43; addi 0,3,31; rlwinm 3,4,0,0,26; rlwinm 0,0,0,0,26; stw 3,-23368(13); stw 0,-23372(13); bl _s80260A24_1; lis 3,-32694; lwz 4,-23368(13); lis 5,-32730; addi 3,3,-17000; addi 5,5,2380; bl _s80260A24_2; 0:; bl _s80260A24_3; cmpwi 3,0; bne 0b; lwz 3,-23372(13); lis 29,-32768; lis 30,-32768; lwz 0,0x10(3); addi 3,29,0; li 5,32; stw 0,0x38(30); lwz 4,-23372(13); lwz 0,0xc(4); stw 0,0x3c(30); lwz 4,-23368(13); bl _s80260A24_4; addi 3,13,-27696; crxor 6,6,6; bl _s80260A24_5; lbz 4,0x0(29); mr 3,31; lbz 5,0x1(29); crxor 6,6,6; lbz 6,0x2(29); lbz 7,0x3(29); extsb 4,4; extsb 5,5; extsb 6,6; extsb 7,7; bl _s80260A24_6; lbz 4,0x4(29); addi 3,31,28; lbz 5,0x5(29); crxor 6,6,6; extsb 4,4; extsb 5,5; bl _s80260A24_7; lbz 4,0x6(29); addi 3,31,52; crxor 6,6,6; bl _s80260A24_8; lbz 4,0x7(29); addi 3,31,72; crxor 6,6,6; bl _s80260A24_9; lbz 0,0x8(30); cmplwi 0,0; bne 1f; addi 4,13,-27692; b 2f; 1:; addi 4,13,-27688; 2:; crxor 6,6,6; addi 3,31,92; bl _s80260A24_10; addi 3,13,-27696; crxor 6,6,6; bl _s80260A24_11; lwz 3,-23372(13); lwz 3,0x10(3); bl _s80260A24_12; lwz 0,0x64(1); lwz 31,0x5c(1); lwz 30,0x58(1); lwz 29,0x54(1); addi 1,1,96; mtspr 8,0"
extern "C" void _s80260A24_0();
extern "C" void _s80260A24_1();
extern "C" void _s80260A24_2();
extern "C" void _s80260A24_3();
extern "C" void _s80260A24_4();
extern "C" void _s80260A24_5();
extern "C" void _s80260A24_6();
extern "C" void _s80260A24_7();
extern "C" void _s80260A24_8();
extern "C" void _s80260A24_9();
extern "C" void _s80260A24_10();
extern "C" void _s80260A24_11();
extern "C" void _s80260A24_12();
extern "C" void f_80260A24() {}
