// 0x80065FF4 SAnimator2::cleanupParticlesDelayed(TRedBlackTree<unsigned (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 10,0x0(4); cmpwi 10,0; beq 3f; 0:; lwz 9,0x1c(10); lwz 11,0x0(9); cmpwi 11,0; beq 2f; li 0,0; 1:; lwz 9,0x1c(11); stw 0,0x78(9); lwz 11,0x10(11); cmpwi 11,0; bne 1b; 2:; lwz 10,0x10(10); cmpwi 10,0; bne 0b; 3:; bl _s80065FF4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80065FF4_0();
extern "C" void f_80065FF4() {}
