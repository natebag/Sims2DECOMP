// 0x80230F8C ELightGrid::LightData::Clear(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lis 11,-32704; addi 9,1,8; lfs f0,-3440(11); addi 6,3,16; li 5,0; stfs f0,0x8(9); stfs f0,0x4(9); stfs f0,0x8(1); lwz 11,0x8(1); lwz 8,0x4(9); lwz 7,0x8(9); stfs f0,0x8(9); stfs f0,0x4(9); stfs f0,0x8(1); stw 11,0x0(3); lwz 0,0x8(1); lwz 11,0x8(9); lwz 10,0x4(9); stw 8,0x4(3); stw 7,0x8(3); stw 0,0x10(3); stw 11,0x8(6); stw 10,0x4(6); stw 5,0x1c(3); stfs f0,0xc(3); addi 1,1,24"
extern "C" void f_80230F8C() {}
