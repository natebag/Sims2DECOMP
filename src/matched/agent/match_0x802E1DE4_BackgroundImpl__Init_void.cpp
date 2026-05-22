// 0x802E1DE4 BackgroundImpl::Init(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 4,32; addi 3,29,872; addi 30,29,8; bl _s802E1DE4_0; lis 9,-32702; li 5,0; addi 9,9,-6344; li 6,0; stw 9,0x32c(30); li 4,25; ori 5,5,32768; mr 3,30; bl _s802E1DE4_1; mr 3,30; bl _s802E1DE4_2; li 0,1; stw 0,0x348(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802E1DE4_0();
extern "C" void _s802E1DE4_1();
extern "C" void _s802E1DE4_2();
extern "C" void f_802E1DE4() {}
