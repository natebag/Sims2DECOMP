// 0x802D4030 EString2::EString2(wchar_t) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); sth 4,0x8(1); mr 30,3; addi 4,1,8; li 0,0; sth 0,0x2(4); bl _s802D4030_0; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802D4030_0();
extern "C" void f_802D4030() {}
