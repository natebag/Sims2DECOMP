// 0x800891B8 CreateASimBaseState::Reset(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 29,0; stw 29,0x28(30); stw 29,0x2c(30); bl _s800891B8_0; li 0,1; lis 3,-32697; stw 29,0xc(30); addi 3,3,23428; stw 29,0x20(30); li 4,0; stw 0,0x1c(30); li 5,8; bl _s800891B8_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800891B8_0();
extern "C" void _s800891B8_1();
extern "C" void f_800891B8() {}
