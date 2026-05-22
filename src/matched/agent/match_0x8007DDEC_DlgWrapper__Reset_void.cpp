// 0x8007DDEC DlgWrapper::Reset(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 0,0; lwz 9,0xac(30); stw 0,0xb8(30); stw 0,0x34(9); bl _s8007DDEC_0; mr 3,30; bl _s8007DDEC_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8007DDEC_0();
extern "C" void _s8007DDEC_1();
extern "C" void f_8007DDEC() {}
