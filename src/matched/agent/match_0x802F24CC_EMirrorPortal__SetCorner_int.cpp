// 0x802F24CC EMirrorPortal::SetCorner(int, (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 4,4,12; lwz 0,0x0(5); lwz 9,0x8(5); lwz 11,0x4(5); add 4,4,3; stwu 0,0x4(4); stw 9,0x8(4); stw 11,0x4(4)"
extern "C" void f_802F24CC() {}
