// 0x80372570 C_MTXTranspose (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-64(1); cmplw 3,4; bne 0f; addi 5,1,16; b 1f; 0:; mr 5,4; 1:; lfs f0,0x0(3); addi 0,1,16; cmplw 5,0; stfs f0,0x0(5); lfs f0,0x10(3); stfs f0,0x4(5); lfs f0,0x20(3); stfs f0,0x8(5); lfs f1,-17964(13); stfs f1,0xc(5); lfs f0,0x4(3); stfs f0,0x10(5); lfs f0,0x14(3); stfs f0,0x14(5); lfs f0,0x24(3); stfs f0,0x18(5); stfs f1,0x1c(5); lfs f0,0x8(3); stfs f0,0x20(5); lfs f0,0x18(3); stfs f0,0x24(5); lfs f0,0x28(3); stfs f0,0x28(5); stfs f1,0x2c(5); bne 2f; mr 3,0; bl _s80372570_0; 2:; lwz 0,0x44(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s80372570_0();
extern "C" void f_80372570() {}
