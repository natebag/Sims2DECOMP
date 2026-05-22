// 0x802386A4 Emitter::Emitter(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s802386A4_0; lis 11,-32697; li 0,0; addi 11,11,-25824; stw 0,0x8c(30); stw 11,0x0(30); addi 9,30,140; stw 0,0x4(9); lis 11,-32704; stw 0,0x8(9); mr 3,30; stw 0,0xc(9); stw 0,0x10(9); stw 0,0x14(9); stw 0,0x18(9); stw 0,0x1c(9); stw 0,0x20(9); stw 0,0x24(9); stw 0,0x28(9); lfs f0,-2268(11); stw 0,0x34(9); stfs f0,0x30(9); stfs f0,0x2c(9); stw 0,0x7c(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802386A4_0();
extern "C" void f_802386A4() {}
