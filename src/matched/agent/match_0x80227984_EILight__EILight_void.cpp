// 0x80227984 EILight::EILight(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; bl _s80227984_0; lis 9,-32704; addi 10,1,8; lfs f0,-6544(9); lis 11,-32697; addi 11,11,-29216; li 9,1; stfs f0,0x8(10); li 6,0; stfs f0,0x4(10); addi 7,30,144; stfs f0,0x8(1); mr 3,30; stw 11,0x0(30); lwz 11,0x8(10); lwz 0,0x8(1); lwz 8,0x4(10); stw 0,0x90(30); stw 9,0x88(30); stw 9,0x7c(30); stw 6,0x80(30); stfs f0,0x8c(30); stw 11,0x8(7); stw 8,0x4(7); stw 6,0x84(30); lwz 0,0x5c(30); stfs f0,0xa4(30); oris 0,0,8; stw 9,0xa8(30); stw 0,0x5c(30); stfs f0,0x9c(30); stfs f0,0xa0(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80227984_0();
extern "C" void f_80227984() {}
