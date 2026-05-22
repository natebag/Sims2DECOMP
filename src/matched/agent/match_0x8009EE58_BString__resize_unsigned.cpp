// 0x8009EE58 BString::resize(unsigned (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s8009EE58_0; mr 5,3; mr 4,29; mr 3,30; bl _s8009EE58_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8009EE58_0();
extern "C" void _s8009EE58_1();
extern "C" void f_8009EE58() {}
