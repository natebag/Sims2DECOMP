// 0x803A0808 PaneItem::SetSize(EVec2 (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); lwz 11,0x4(4); lwz 9,0x0(4); rlwinm 0,0,0,31,29; stw 0,0x4(3); stw 9,0x14(3); stw 11,0x18(3)"
extern "C" void f_803A0808() {}
