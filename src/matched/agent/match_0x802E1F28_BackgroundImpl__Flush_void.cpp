// 0x802E1F28 BackgroundImpl::Flush(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,3; lwz 9,0x0(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; mr. 29,3; bne 0f; addi 30,1,8; mr 3,30; bl _s802E1F28_0; li 5,0; li 4,1; mr 3,30; bl _s802E1F28_1; li 3,16; bl _s802E1F28_2; mr 9,3; li 0,1; mr 4,9; stw 29,0xc(9); stw 0,0x0(9); mr 3,31; stw 30,0x4(9); bl _s802E1F28_3; li 4,-1; mr 3,30; bl _s802E1F28_4; mr 3,30; bl _s802E1F28_5; mr 3,30; li 4,2; bl _s802E1F28_6; 0:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s802E1F28_0();
extern "C" void _s802E1F28_1();
extern "C" void _s802E1F28_2();
extern "C" void _s802E1F28_3();
extern "C" void _s802E1F28_4();
extern "C" void _s802E1F28_5();
extern "C" void _s802E1F28_6();
extern "C" void f_802E1F28() {}
