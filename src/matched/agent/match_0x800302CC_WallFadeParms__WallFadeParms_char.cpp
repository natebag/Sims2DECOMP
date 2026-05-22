// 0x800302CC WallFadeParms::WallFadeParms(char (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32707; fsubs f9,f2,f1; lfs f10,0xe74(9); lis 10,-32707; lis 9,-32707; lis 8,-32707; fdivs f8,f10,f9; lis 7,-32707; lfs f11,0xe70(9); lis 11,-32698; lfs f12,0xe78(10); mr 9,3; lfs f13,0xe7c(8); addi 11,11,-19784; lfs f0,0xe80(7); li 0,1; stw 11,0x2c(9); stw 0,0x0(9); stfs f11,0xc(9); stfs f12,0x14(9); stfs f13,0x18(9); stfs f0,0x1c(9); stw 5,0x28(9); stfs f2,0x4(9); stfs f1,0x8(9); stfs f10,0x10(9); stfs f9,0x20(9); stfs f8,0x24(9)"
extern "C" void f_800302CC() {}
