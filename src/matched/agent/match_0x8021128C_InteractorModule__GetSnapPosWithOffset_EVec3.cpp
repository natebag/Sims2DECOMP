// 0x8021128C InteractorModule::GetSnapPosWithOffset(EVec3 (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 30,3; mr 5,4; addi 3,1,16; addi 4,1,20; bl _s8021128C_0; lwz 0,0x10(1); lis 6,17200; lwz 9,0x14(1); xoris 0,0,32768; mr 10,11; stw 0,0x1c(1); xoris 9,9,32768; lis 8,-32704; lis 7,-32697; stw 6,0x18(1); mr 3,30; lfd f12,-11136(8); lfd f13,0x18(1); stw 9,0x1c(1); fsub f13,f13,f12; lwz 9,0x5e94(7); stw 6,0x18(1); frsp f13,f13; stfs f13,0x8(1); lfd f0,0x18(1); fmr f11,f13; fsub f0,f0,f12; frsp f0,f0; stfs f0,0xc(1); lfs f13,0x50(9); lfs f12,0x4c(9); fadds f0,f0,f13; fadds f11,f11,f12; stfs f0,0x4(30); stfs f11,0x0(30); lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s8021128C_0();
extern "C" void f_8021128C() {}
