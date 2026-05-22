// 0x800689FC SAnimator2::UpdateAnimationValidity(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); li 10,1; addi 11,9,820; lwz 9,0x8(11); cmpwi 9,0; blt 0f; mulli 9,9,176; lwz 0,0x44(11); add 0,0,9; b 1f; 0:; li 0,0; 1:; cmpwi 0,0; bne 2f; li 10,0; 2:; lwz 9,0x8(3); stw 10,0x394(9)"
extern "C" void f_800689FC() {}
