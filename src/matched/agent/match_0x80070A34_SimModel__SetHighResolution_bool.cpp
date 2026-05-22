// 0x80070A34 SimModel::SetHighResolution(bool) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x138(3); xoris 0,4,1; stw 4,0x150(3); stw 0,0xc(9)"
extern "C" void f_80070A34() {}
