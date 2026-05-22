// 0x803C3988 TArray<ESMSStrip, (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 11,5,-1; cmpwi 5,0; beqlr; 0:; mr 9,3; addi 5,11,-1; addi 10,4,52; addi 3,9,52; li 11,48; 1:; lwz 0,0x0(4); addic. 11,11,-24; stw 0,0x0(9); lwz 0,0x4(4); stw 0,0x4(9); lwz 0,0x8(4); stw 0,0x8(9); lwz 0,0xc(4); stw 0,0xc(9); lwz 0,0x10(4); stw 0,0x10(9); lwz 0,0x14(4); addi 4,4,24; stw 0,0x14(9); addi 9,9,24; bne 1b; lwz 0,0x0(4); mr 11,5; mr 4,10; cmpwi 11,-1; stw 0,0x0(9); bne 0b"
extern "C" void f_803C3988() {}
