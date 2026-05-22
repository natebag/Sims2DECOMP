// 0x802A8C28 EAStringC::EAStringC(EAStringC (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x0(4); mr 11,3; stw 10,0x0(11); lhz 9,0x0(10); addi 9,9,1; sth 9,0x0(10)"
extern "C" void f_802A8C28() {}
