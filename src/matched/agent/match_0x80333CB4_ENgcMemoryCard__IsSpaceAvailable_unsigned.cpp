// 0x80333CB4 ENgcMemoryCard::IsSpaceAvailable(unsigned (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; li 3,1; stw 0,0x0(6)"
extern "C" void f_80333CB4() {}
