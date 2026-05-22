// 0x8008532C WrapperPaneBase::SetItemShader(ItemType, (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,6; bl _s8008532C_0; mr 30,3; bl _s8008532C_1; mr 3,30; mr 4,29; bl _s8008532C_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8008532C_0();
extern "C" void _s8008532C_1();
extern "C" void _s8008532C_2();
extern "C" void f_8008532C() {}
