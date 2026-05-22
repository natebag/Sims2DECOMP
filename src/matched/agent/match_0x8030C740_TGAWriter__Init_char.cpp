// 0x8030C740 TGAWriter::Init(char (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 27,7; mr 29,5; mr 28,6; bl _s8030C740_0; mr 3,30; bl _s8030C740_1; stw 29,0x18(30); stw 28,0x1c(30); lhz 0,0x10(27); sth 0,0x12(30); lhz 9,0x12(27); sth 9,0x14(30); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8030C740_0();
extern "C" void _s8030C740_1();
extern "C" void f_8030C740() {}
