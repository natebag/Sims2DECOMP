// 0x80389180 GXRedirectWriteGatherPipe (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); li 31,0; stw 30,0x18(1); stw 29,0x14(1); addi 29,3,0; bl _s80389180_0; mr 30,3; bl _s80389180_1; 0:; bl _s80389180_2; rlwinm. 0,3,0,31,31; bne 0b; lis 3,3073; addi 3,3,-32768; bl _s80389180_3; lbz 0,-21948(13); cmplwi 0,0; beq 1f; lwz 5,-17720(13); li 4,0; lwz 0,0x8(5); rlwimi 0,4,4,27,27; stw 0,0x8(5); lwz 0,0x8(5); lwz 3,-21996(13); sth 0,0x2(3); lwz 0,0x8(5); rlwimi 0,4,2,29,29; stw 0,0x8(5); lwz 0,0x8(5); rlwimi 0,4,3,28,28; stw 0,0x8(5); lwz 0,0x8(5); lwz 3,-21996(13); sth 0,0x2(3); 1:; lwz 4,-22000(13); rlwimi 31,29,0,6,26; lwz 3,-21960(13); addi 5,31,0; lwz 4,0x14(4); rlwinm 4,4,0,6,4; addis 0,4,-32768; stw 0,0x18(3); li 4,0; lis 0,1024; lwz 3,-22000(13); rlwimi 5,4,26,5,5; stw 4,0xc(3); lwz 3,-22000(13); stw 0,0x10(3); lwz 3,-22000(13); stw 5,0x14(3); bl _s80389180_4; mr 3,30; bl _s80389180_5; lis 3,-13311; lwz 0,0x24(1); lwz 31,0x1c(1); addi 3,3,-32768; lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80389180_0();
extern "C" void _s80389180_1();
extern "C" void _s80389180_2();
extern "C" void _s80389180_3();
extern "C" void _s80389180_4();
extern "C" void _s80389180_5();
extern "C" void f_80389180() {}
