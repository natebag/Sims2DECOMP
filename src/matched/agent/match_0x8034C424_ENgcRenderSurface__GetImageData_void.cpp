// 0x8034C424 ENgcRenderSurface::GetImageData(void (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x28(3); mr 6,4; lwz 5,0x4(3); lwz 9,0x28(11); lwz 4,0x0(3); lwz 3,0x74(9); bl _s8034C424_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8034C424_0();
extern "C" void f_8034C424() {}
