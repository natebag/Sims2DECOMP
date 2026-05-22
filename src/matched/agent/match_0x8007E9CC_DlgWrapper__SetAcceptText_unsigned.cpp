// 0x8007E9CC DlgWrapper::SetAcceptText(unsigned (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 30,0xac(3); lwz 3,0x40(30); bl _s8007E9CC_0; mr 3,30; li 4,0; bl _s8007E9CC_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8007E9CC_0();
extern "C" void _s8007E9CC_1();
extern "C" void f_8007E9CC() {}
