// 0x8014941C TTabScratchEntry::TTabScratchEntry(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32698; li 7,16; mr 8,3; addi 9,9,20728; mtspr 9,7; lis 11,-32698; stw 9,0x0(8); addi 11,11,21232; addi 9,8,8; li 0,0; li 10,0; 0:; stw 11,0x0(9); sth 0,0x4(9); sth 0,0x6(9); sth 0,0x8(9); stw 10,0xc(9); addi 9,9,16; bdnz 0b; li 0,0; li 9,50; li 11,-1; li 10,3; sth 0,0x6(8); mr 3,8; sth 9,0x114(8); sth 11,0x116(8); stw 10,0x108(8); stw 0,0x118(8); sth 0,0x110(8); sth 0,0x4(8)"
extern "C" void f_8014941C() {}
