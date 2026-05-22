// 0x80240258 PCgetLastError (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32694; li 0,0; lwz 3,-26472(9); stw 0,-26472(9)"
extern "C" void f_80240258() {}
