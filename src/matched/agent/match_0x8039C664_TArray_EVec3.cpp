// 0x8039C664 TArray<EVec3, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 4,0x4(30); lwz 3,0x0(30); bl _s8039C664_0; lwz 29,0x0(30); bl _s8039C664_1; mr 4,29; bl _s8039C664_2; mr 3,30; bl _s8039C664_3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8039C664_0();
extern "C" void _s8039C664_1();
extern "C" void _s8039C664_2();
extern "C" void _s8039C664_3();
extern "C" void f_8039C664() {}
