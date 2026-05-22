// 0x800916F8 MUStatesFormat::Reset(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 29,0; stw 29,0x1c(30); li 0,2; stw 29,0x20(30); li 4,17; lwz 9,0x8(30); lwz 11,0x98(9); stw 0,0xac(11); lwz 9,0x8(30); lwz 3,0x98(9); bl _s800916F8_0; mr 3,30; li 4,14; bl _s800916F8_1; li 0,1; stw 29,0x20(30); stw 0,0x1c(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800916F8_0();
extern "C" void _s800916F8_1();
extern "C" void f_800916F8() {}
