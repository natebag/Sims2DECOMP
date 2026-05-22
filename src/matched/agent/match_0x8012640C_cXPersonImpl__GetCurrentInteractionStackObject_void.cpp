// 0x8012640C cXPersonImpl::GetCurrentInteractionStackObject(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x534(3); cmpwi 0,0; bne 0f; li 3,0; b 1f; 0:; addi 3,3,304; lis 0,-13108; lwz 9,0x2a8(3); ori 0,0,52429; mulhwu 0,9,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 9,0,9; mulli 9,9,68; add 3,3,9; bl _s8012640C_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8012640C_0();
extern "C" void f_8012640C() {}
