// 0x80386C60 __CARDWrite (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; mulli 9,3,272; stw 0,0x4(1); lis 8,-32688; stwu 1,-8(1); addi 0,8,-24000; add 8,0,9; lwz 0,0x0(8); cmpwi 0,0; bne 0f; li 3,-3; b 1f; 0:; stw 7,0xd4(8); lis 7,-32712; addi 0,7,27512; lhz 7,0xa(8); divw 5,5,7; stw 5,0xac(8); stw 4,0xb0(8); mr 4,0; stw 6,0xb4(8); bl _s80386C60_0; 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80386C60_0();
extern "C" void f_80386C60() {}
