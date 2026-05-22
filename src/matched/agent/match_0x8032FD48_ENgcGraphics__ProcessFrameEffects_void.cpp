// 0x8032FD48 ENgcGraphics::ProcessFrameEffects(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); mr 5,3; lwz 0,0x320(5); cmpwi 0,0; beq 0f; addi 9,5,768; lfs f0,0x2f8(5); lfs f13,0x300(5); lis 11,-32702; lfs f11,0x8(9); lis 3,-32691; lfs f12,0x4(9); fmuls f13,f13,f0; lfs f3,0x2e8(5); fmuls f11,f11,f0; lfs f10,0x1894(11); fmuls f12,f12,f0; lfs f1,0x2e0(5); addi 3,3,21688; lfs f2,0x2e4(5); fmuls f3,f3,f10; lfs f4,0x2f4(5); addi 4,1,8; stfs f13,0x8(1); addi 5,5,780; stfs f12,0xc(1); stfs f11,0x10(1); bl _s8032FD48_0; 0:; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s8032FD48_0();
extern "C" void f_8032FD48() {}
