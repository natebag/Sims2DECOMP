// 0x800578D8 EMemoryMeterWin::EMemoryMeterWin(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 11,-32707; lis 9,-32698; lfs f0,0x3ae4(11); mr 30,3; li 0,0; addi 9,9,-14032; stw 9,0x4(30); stfs f0,0x20(30); stw 0,0x24(30); stw 0,0x0(30); stfs f0,0x8(30); stfs f0,0x10(30); stw 0,0x14(30); stfs f0,0x18(30); stw 0,0x1c(30); bl _s800578D8_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800578D8_0();
extern "C" void f_800578D8() {}
