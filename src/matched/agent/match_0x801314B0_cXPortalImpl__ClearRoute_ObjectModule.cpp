// 0x801314B0 cXPortalImpl::ClearRoute(ObjectModule (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 28,0x8(1); stw 0,0x24(1); mr 30,3; mr 28,4; lwz 9,0x0(30); fmr f31,f1; li 31,0; lha 3,0x110(9); lwz 0,0x114(9); add 3,30,3; mtspr 8,0; blrl; mr 29,3; cmpw 31,29; bge 3f; 0:; lwz 9,0x0(30); mr 4,31; lha 3,0x108(9); lwz 0,0x10c(9); add 3,30,3; mtspr 8,0; blrl; mr. 11,3; beq 1f; lwz 9,0x4(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; b 2f; 1:; li 3,0; 2:; mr 4,28; fmr f1,f31; addi 31,31,1; bl _s801314B0_0; cmpw 31,29; blt 0b; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x8(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s801314B0_0();
extern "C" void f_801314B0() {}
