// 0x800BB3C0 HouseImpl::HouseImpl(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 30,3; addi 9,9,-3248; addi 3,30,4; stw 9,0x0(30); bl _s800BB3C0_0; lis 9,-32698; lis 11,-32698; addi 9,9,-3440; addi 11,11,-3408; stw 9,0x10(30); addi 3,30,24; stw 11,0x0(30); bl _s800BB3C0_1; li 0,0; mr 3,30; stw 0,0x20(30); stw 0,0x14(30); stw 0,0x1c(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BB3C0_0();
extern "C" void _s800BB3C0_1();
extern "C" void f_800BB3C0() {}
