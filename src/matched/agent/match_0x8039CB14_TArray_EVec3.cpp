// 0x8039CB14 TArray<EVec3, (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s8039CB14_0; mr 4,29; mr 3,30; bl _s8039CB14_1; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8039CB14_0();
extern "C" void _s8039CB14_1();
extern "C" void f_8039CB14() {}
