// 0x800653F8 SAnimator2::GetBonePosAndDirForParticle(unsigned (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x8(3); addi 3,3,820; bl _s800653F8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800653F8_0();
extern "C" void f_800653F8() {}
