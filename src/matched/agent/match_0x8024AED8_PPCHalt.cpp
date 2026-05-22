// 0x8024AED8 PPCHalt (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="sync; 0:; ori 0,0,0; li 3,0; ori 0,0,0; b 0b"
extern "C" void f_8024AED8() {}
