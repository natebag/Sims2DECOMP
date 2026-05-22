// 0x80336368 ENgcMovie::PlayerGetTotalFrame(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32691; addi 9,9,14656; lwz 0,0xa0(9); cmplwi 0,0; li 3,0; beqlr; lwz 3,0x50(9)"
extern "C" int f_80336368() {}
