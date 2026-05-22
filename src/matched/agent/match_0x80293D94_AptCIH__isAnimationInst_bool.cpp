// 0x80293D94 AptCIH::isAnimationInst(bool) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; li 29,0; bl _s80293D94_0; cmpwi 3,18; bne 1f; cmpwi 30,0; bne 0f; mr 3,31; bl _s80293D94_1; cmpwi 3,0; bne 1f; 0:; li 29,1; 1:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80293D94_0();
extern "C" void _s80293D94_1();
extern "C" void f_80293D94() {}
