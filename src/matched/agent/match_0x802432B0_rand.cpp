// 0x802432B0 rand (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-27948(13); lis 0,16838; ori 0,0,20077; lwz 3,0x58(9); mullw 3,3,0; addi 3,3,12345; stw 3,0x58(9); rlwinm 3,3,0,1,31"
extern "C" void f_802432B0() {}
