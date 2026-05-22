// 0x800EB15C cXObjectImpl::HideForCutaway(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lha 0,0x5c(3); cmpwi 0,0; bne 0f; addi 3,31,40; li 4,8; bl _s800EB15C_0; lhz 0,0x0(3); andi. 9,0,1024; beq 1f; 0:; li 30,1; 1:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800EB15C_0();
extern "C" void f_800EB15C() {}
