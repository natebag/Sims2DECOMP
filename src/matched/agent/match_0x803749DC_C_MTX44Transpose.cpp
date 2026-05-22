// 0x803749DC C_MTX44Transpose (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-80(1); cmplw 3,4; bne 0f; addi 5,1,16; b 1f; 0:; mr 5,4; 1:; lfs f0,0x0(3); addi 0,1,16; cmplw 5,0; stfs f0,0x0(5); lfs f0,0x10(3); stfs f0,0x4(5); lfs f0,0x20(3); stfs f0,0x8(5); lfs f0,0x30(3); stfs f0,0xc(5); lfs f0,0x4(3); stfs f0,0x10(5); lfs f0,0x14(3); stfs f0,0x14(5); lfs f0,0x24(3); stfs f0,0x18(5); lfs f0,0x34(3); stfs f0,0x1c(5); lfs f0,0x8(3); stfs f0,0x20(5); lfs f0,0x18(3); stfs f0,0x24(5); lfs f0,0x28(3); stfs f0,0x28(5); lfs f0,0x38(3); stfs f0,0x2c(5); lfs f0,0xc(3); stfs f0,0x30(5); lfs f0,0x1c(3); stfs f0,0x34(5); lfs f0,0x2c(3); stfs f0,0x38(5); lfs f0,0x3c(3); stfs f0,0x3c(5); bne 2f; mr 3,0; bl _s803749DC_0; 2:; lwz 0,0x54(1); addi 1,1,80; mtspr 8,0"
extern "C" void _s803749DC_0();
extern "C" void f_803749DC() {}
