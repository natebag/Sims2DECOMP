// 0x80327FA8 EScratchBuffMan::Init(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0xc(31); cmpwi 0,0; bne 0f; lwz 11,-26824(13); lwz 9,0x338(11); lha 3,0x50(9); lwz 0,0x54(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; stw 3,0x10(31); beq 0f; bl _s80327FA8_0; lwz 4,0x10(31); li 5,16; li 6,0; li 7,0; bl _s80327FA8_1; stw 3,0xc(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80327FA8_0();
extern "C" void _s80327FA8_1();
extern "C" void f_80327FA8() {}
