// 0x802D3868 EString::ExtractExtension(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-280(1); mfspr 0,8; stmw 30,0x110(1); stw 0,0x11c(1); mr 30,3; lwz 4,0x0(4); addi 3,1,8; bl _s802D3868_0; mr 4,3; mr 3,30; bl _s802D3868_1; mr 3,30; lwz 0,0x11c(1); mtspr 8,0; lmw 30,0x110(1); addi 1,1,280"
extern "C" void _s802D3868_0();
extern "C" void _s802D3868_1();
extern "C" void f_802D3868() {}
