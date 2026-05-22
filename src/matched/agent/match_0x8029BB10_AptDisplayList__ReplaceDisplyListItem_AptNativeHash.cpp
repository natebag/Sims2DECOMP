// 0x8029BB10 AptDisplayList::ReplaceDisplyListItem(AptNativeHash (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,6; mr 28,3; lwz 9,0x4(30); mr 29,4; mr 31,5; mr 27,7; lwz 0,0x0(9); cmpwi 0,0; beq 0f; bl _s8029BB10_0; mr 3,28; mr 4,29; mr 5,30; mr 6,27; bl _s8029BB10_1; b 2f; 0:; lwz 0,0x5c(31); andi. 11,0,32768; bne 2f; lwz 0,0x14(9); andi. 11,0,8; beq 1f; lwz 4,0x8(9); addi 3,31,40; bl _s8029BB10_2; 1:; lwz 5,0x4(30); lwz 0,0x14(5); andi. 9,0,4; beq 2f; lwz 9,0x4(5); addi 11,31,16; lwz 0,0x0(9); lwz 10,0x4(9); lwz 8,0x8(9); lwz 7,0xc(9); stw 0,0x10(31); stw 10,0x4(11); stw 8,0x8(11); stw 7,0xc(11); lwz 0,0x14(9); lwz 10,0x10(9); stw 0,0x14(11); stw 10,0x10(11); 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8029BB10_0();
extern "C" void _s8029BB10_1();
extern "C" void _s8029BB10_2();
extern "C" void f_8029BB10() {}
