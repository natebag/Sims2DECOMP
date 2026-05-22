// 0x80209268 ObjectSlot::IsSurface(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f0,0x50(8); stfs f0,0x58(8); stw 9,0x40(8); stw 11,0x48(8); addi 1,1,16"
extern "C" void f_80209268() {}
