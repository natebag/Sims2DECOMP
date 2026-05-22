// 0x802E1CB0 BackgroundImpl::~BackgroundImpl(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; lis 11,-32697; mr 30,3; addi 9,9,-23208; addi 11,11,-23176; mr 29,4; stw 9,0x340(30); addi 3,30,872; stw 11,0x0(30); li 4,2; bl _s802E1CB0_0; addi 3,30,844; li 4,2; bl _s802E1CB0_1; addi 3,30,8; li 4,0; bl _s802E1CB0_2; mr 3,30; mr 4,29; bl _s802E1CB0_3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802E1CB0_0();
extern "C" void _s802E1CB0_1();
extern "C" void _s802E1CB0_2();
extern "C" void _s802E1CB0_3();
extern "C" void f_802E1CB0() {}
