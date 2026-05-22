// 0x8009AF28 TheSimsMaxisLogoState::TheSimsMaxisLogoState(int) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32698; mr 9,3; li 0,0; li 7,-1; addi 11,11,-7360; li 8,1; stw 4,0x0(9); lis 6,-32706; stw 7,0xc(9); addi 10,9,36; stw 8,0x14(9); stw 11,0x18(9); stw 7,0x4(9); stw 0,0x8(9); stw 0,0x10(9); stw 0,0x1c(9); stw 0,0x20(9); lfs f0,-29184(6); stfs f0,0x24(9); stw 0,0xc(10); stfs f0,0x8(10); stfs f0,0x4(10)"
extern "C" void f_8009AF28() {}
