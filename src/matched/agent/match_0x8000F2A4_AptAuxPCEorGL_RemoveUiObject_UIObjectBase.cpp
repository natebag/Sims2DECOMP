// 0x8000F2A4 AptAuxPCEorGL_RemoveUiObject(UIObjectBase (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8000F8F4" lines="fcmpu 0,f12,f0; cror 3,2,1; bns 0f; lis 9,-32707; lis 11,-32707; lis 10,-32707; lfs f0,-10116(9); lfs f13,-10112(11); lfs f12,-10108(10); stfs f0,0x20(1); stfs f13,0x28(1); stfs f12,0x2c(1); stfs f24,0x24(1); 0:; mr 3,27; mr 4,31; bl _s8000F2A4_0; lwz 11,0xc(27); li 0,0; cmpw 25,31; stw 22,0x8(11); lwz 9,0xc(27); lfs f13,0x20(1); lwz 11,0x2c(9); stfs f13,0x0(11); lfs f0,0x24(1); stfs f0,0x4(11); lfs f13,0x28(1); stfs f13,0x8(11); lfs f0,0x2c(1); stfs f0,0xc(11); lwz 9,0xc(27); stw 0,0x0(9); lwz 11,0x10(27); stw 0,0x0(11)"
extern "C" void _s8000F2A4_0();
extern "C" void f_8000F8F4();
extern "C" void f_8000F2A4() {}
