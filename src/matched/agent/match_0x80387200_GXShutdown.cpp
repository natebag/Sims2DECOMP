// 0x80387200 __GXShutdown (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); cmpwi 3,0; bne 6f; lwz 0,-21968(13); cmplwi 0,0; bne 2f; lwz 3,-21988(13); addi 6,3,78; lhz 4,0x0(6); addi 5,3,80; b 0f; 0:; b 1f; 1:; mr 0,4; lhz 4,0x0(6); lhz 3,0x0(5); cmplw 4,0; bne 1b; rlwinm 0,4,16,0,15; or 0,0,3; stw 0,-21984(13); bl _s80387200_0; stw 4,-21972(13); li 0,1; stw 3,-21976(13); li 3,0; stw 0,-21968(13); b 8f; 2:; bl _s80387200_1; lwz 5,-21988(13); addi 6,5,78; lhz 7,0x0(6); addi 5,5,80; b 3f; 3:; b 4f; 4:; mr 0,7; lhz 7,0x0(6); lhz 10,0x0(5); cmplw 7,0; bne 4b; lwz 6,-21972(13); li 0,0; lwz 5,-21976(13); rlwinm 9,7,16,0,15; subfc 8,6,4; subfe 5,5,3; li 7,10; xoris 6,5,32768; xoris 5,0,32768; subfc 0,7,8; subfe 5,5,6; subfe 5,6,6; neg 5,5; cmpwi 5,0; or 5,9,10; beq 5f; li 3,0; b 8f; 5:; lwz 0,-21984(13); cmplw 5,0; beq 7f; stw 4,-21972(13); stw 3,-21976(13); li 3,0; stw 5,-21984(13); b 8f; 6:; li 3,0; bl _s80387200_2; li 3,0; bl _s80387200_3; li 3,0; bl _s80387200_4; li 31,0; lis 3,-13311; stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); bl _s80387200_5; lwz 3,-21996(13); li 4,3; li 0,1; sth 31,0x2(3); lwz 3,-21996(13); sth 4,0x4(3); lwz 3,-17720(13); stb 0,0x5aa(3); bl _s80387200_6; 7:; li 3,1; 8:; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80387200_0();
extern "C" void _s80387200_1();
extern "C" void _s80387200_2();
extern "C" void _s80387200_3();
extern "C" void _s80387200_4();
extern "C" void _s80387200_5();
extern "C" void _s80387200_6();
extern "C" void f_80387200() {}
