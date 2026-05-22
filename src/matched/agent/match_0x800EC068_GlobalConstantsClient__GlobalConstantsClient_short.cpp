// 0x800EC068 GlobalConstantsClient::GlobalConstantsClient(short) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32698; sth 4,0x4(3); addi 9,9,6232; stw 9,0x0(3)"
extern "C" void f_800EC068() {}
