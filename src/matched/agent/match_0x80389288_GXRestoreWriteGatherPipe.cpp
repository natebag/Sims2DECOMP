// 0x80389288 GXRestoreWriteGatherPipe (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); li 31,0; stw 30,0x10(1); bl _s80389288_0; lis 5,-13311; li 4,0; stb 4,-32768(5); li 6,24; subfic 0,6,31; stb 4,-32768(5); cmplwi 6,31; mtspr 9,0; mr 30,3; stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); stb 4,-32768(5); bge 1f; 0:; stb 4,-32768(5); bdnz 0b; 1:; bl _s80389288_1; 2:; bl _s80389288_2; rlwinm. 0,3,0,31,31; bne 2b; lis 3,3073; addi 3,3,-32768; bl _s80389288_3; lwz 4,-21960(13); li 6,0; lwz 3,-22000(13); lwz 0,0x0(4); rlwinm 0,0,0,2,31; stw 0,0xc(3); lwz 4,-21960(13); lwz 3,-22000(13); lwz 0,0x4(4); rlwinm 0,0,0,2,31; stw 0,0x10(3); lwz 4,-21960(13); lwz 3,-22000(13); lwz 0,0x18(4); rlwimi 31,0,0,6,26; addi 0,31,0; rlwimi 0,6,26,5,5; stw 0,0x14(3); lbz 0,-21948(13); cmplwi 0,0; beq 3f; lwz 5,-17720(13); li 4,1; lwz 0,0x10(5); rlwimi 0,4,0,31,31; stw 0,0x10(5); lwz 0,0x10(5); rlwimi 0,4,1,30,30; stw 0,0x10(5); lwz 0,0x10(5); lwz 3,-21996(13); sth 0,0x4(3); lwz 0,0x8(5); rlwimi 0,4,2,29,29; stw 0,0x8(5); lwz 0,0x8(5); rlwimi 0,6,3,28,28; stw 0,0x8(5); lwz 0,0x8(5); lwz 3,-21996(13); sth 0,0x2(3); lwz 0,0x8(5); rlwimi 0,4,4,27,27; stw 0,0x8(5); lwz 0,0x8(5); lwz 3,-21996(13); sth 0,0x2(3); 3:; bl _s80389288_4; mr 3,30; bl _s80389288_5; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80389288_0();
extern "C" void _s80389288_1();
extern "C" void _s80389288_2();
extern "C" void _s80389288_3();
extern "C" void _s80389288_4();
extern "C" void _s80389288_5();
extern "C" void f_80389288() {}
