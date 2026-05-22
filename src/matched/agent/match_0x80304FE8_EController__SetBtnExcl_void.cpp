// 0x80304FE8 EController::SetBtnExcl(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x200(3); li 0,1; stw 0,0x78(9)"
extern "C" void f_80304FE8() {}
