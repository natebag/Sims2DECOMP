// 0x80239B50 EmitterSpr3dCamaraXYProcessCB(void (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 8,-26704(13); mr 10,3; lis 9,-32704; lis 11,-32704; lfs f0,0x280(8); lis 7,-32704; lfs f12,-1860(9); stfs f0,0x30(10); lwz 9,0x88(10); lfs f0,0x284(8); lfs f13,-1856(11); stfs f0,0x34(10); stfs f12,0x38(10); stfs f13,0xd4(9); lfs f0,-1852(7); lwz 9,0x88(10); stfs f13,0xd0(9); lwz 11,0x88(10); stfs f0,0x110(11); lwz 9,0x88(10); stfs f0,0x10c(9); bl _s80239B50_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80239B50_0();
extern "C" void f_80239B50() {}
