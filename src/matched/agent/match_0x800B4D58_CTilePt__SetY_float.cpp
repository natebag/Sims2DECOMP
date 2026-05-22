// 0x800B4D58 CTilePt::SetY(float) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); fctiwz f0,f1; stfd f0,0x8(1); lwz 9,0xc(1); stb 9,0x1(3); extsb 3,9; addi 1,1,16"
extern "C" void f_800B4D58() {}
