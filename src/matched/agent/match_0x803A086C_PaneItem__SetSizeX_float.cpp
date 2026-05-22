// 0x803A086C PaneItem::SetSizeX(float) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); stfs f1,0x14(3); rlwinm 0,0,0,31,29; stw 0,0x4(3)"
extern "C" void f_803A086C() {}
