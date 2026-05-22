// 0x80348DDC ENgcRenderer::ScrambleRect(EDLEntry (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); mr 9,4; addi 5,1,16; lfs f11,0x14(9); addi 4,1,8; lfs f13,0x8(9); lfs f12,0xc(9); lfs f0,0x10(9); lfs f1,0x4(9); stfs f13,0x8(1); stfs f12,0xc(1); stfs f0,0x10(1); stfs f11,0x14(1); bl _s80348DDC_0; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s80348DDC_0();
extern "C" void f_80348DDC() {}
