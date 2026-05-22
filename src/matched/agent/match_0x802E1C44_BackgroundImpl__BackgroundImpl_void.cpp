// 0x802E1C44 BackgroundImpl::BackgroundImpl(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s802E1C44_0; addi 3,30,8; bl _s802E1C44_1; lis 9,-32697; lis 11,-32697; addi 9,9,-23208; addi 11,11,-23176; stw 9,0x340(30); addi 3,30,844; stw 11,0x0(30); bl _s802E1C44_2; addi 3,30,872; bl _s802E1C44_3; li 0,0; mr 3,30; stw 0,0x348(30); stw 30,-22756(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E1C44_0();
extern "C" void _s802E1C44_1();
extern "C" void _s802E1C44_2();
extern "C" void _s802E1C44_3();
extern "C" void f_802E1C44() {}
