// 0x80375030 InteractorModule::PlacementObject::ResetDirection(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xF0840000; .long 0x10A12956; .long 0xE0830028; .long 0xF0C40010; .long 0x10E239D6; .long 0xE1030020; .long 0xF0A40008; .long 0x10832116; .long 0xF0E40018; .long 0xF1040020; .long 0xE0A30030; .long 0xE0C30038; .long 0xF0840028; .long 0xF0A40030; .long 0xF0C40038"
extern "C" int f_80375030() {}
