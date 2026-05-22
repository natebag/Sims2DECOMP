// 0x802D4CAC EString2::operator+=(wchar_t) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 5,4; addi 3,1,8; mr 4,30; mr 29,3; bl _s802D4CAC_0; lwz 4,0x8(1); mr 3,30; bl _s802D4CAC_1; lwz 4,0x8(1); mr 3,29; bl _s802D4CAC_2; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802D4CAC_0();
extern "C" void _s802D4CAC_1();
extern "C" void _s802D4CAC_2();
extern "C" void f_802D4CAC() {}
