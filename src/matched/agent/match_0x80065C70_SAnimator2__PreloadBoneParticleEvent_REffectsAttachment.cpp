// 0x80065C70 SAnimator2::PreloadBoneParticleEvent(REffectsAttachment (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; lwz 9,0x14(29); lwz 0,0x18(29); subf 0,9,0; srawi. 9,0,3; mtspr 9,9; ble 2f; mfspr 31,9; lis 28,-32692; li 30,0; 0:; lwz 9,0x14(29); add 9,9,30; lwz 4,0x4(9); cmpwi 4,0; beq 1f; addi 3,28,6092; bl _s80065C70_0; 1:; addi 30,30,8; addic. 31,31,-1; bne 0b; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80065C70_0();
extern "C" void f_80065C70() {}
