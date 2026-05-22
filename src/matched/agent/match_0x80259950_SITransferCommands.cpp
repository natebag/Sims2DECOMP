// 0x80259950 SITransferCommands (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lis 0,-32768; stw 0,0x6438(3)"
extern "C" void f_80259950() {}
