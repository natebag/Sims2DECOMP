// 0x8012C08C cXPersonImpl::InitWantFearIcons(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 10,0x4(3); lwz 30,-21476(13); lwz 9,0x4(10); lwz 11,0x0(30); lha 3,0x1b0(9); lwz 9,0x1b4(9); addi 29,11,184; add 3,10,3; lha 0,0xb8(11); mtspr 8,9; add 30,30,0; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; bl _s8012C08C_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8012C08C_0();
extern "C" void f_8012C08C() {}
