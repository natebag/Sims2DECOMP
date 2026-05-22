// 0x801479BC TreeSimImpl::GetCurrentPrimitive(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lwz 11,0x0(3); lwz 9,0x18(11); lha 3,0x48(9); lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; lwz 29,0x10(30); bl _s801479BC_0; mr 4,3; lha 5,0x2(30); mr 3,29; addi 6,1,8; bl _s801479BC_1; cmpwi 3,0; bne 0f; li 3,-1; b 1f; 0:; lhz 3,0x8(1); rlwinm 3,3,0,17,31; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801479BC_0();
extern "C" void _s801479BC_1();
extern "C" void f_801479BC() {}
