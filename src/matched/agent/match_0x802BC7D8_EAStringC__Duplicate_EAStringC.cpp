// 0x802BC7D8 EAStringC::Duplicate(EAStringC (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,4; mr 28,3; lwz 9,0x0(27); lhz 29,0x2(9); mr 4,29; bl _s802BC7D8_0; lwz 30,0x0(28); mr 5,29; lwz 4,0x0(27); addi 30,30,8; addi 4,4,8; mr 3,30; crxor 6,6,6; bl _s802BC7D8_1; li 0,0; mr 3,28; stbx 0,30,29; lwz 9,0x0(28); sth 29,0x2(9); lwz 11,0x0(27); lwz 9,0x0(28); lhz 0,0x6(11); sth 0,0x6(9); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802BC7D8_0();
extern "C" void _s802BC7D8_1();
extern "C" void f_802BC7D8() {}
