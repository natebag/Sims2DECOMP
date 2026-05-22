// 0x8025D950 __DVDSetImmCommand (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 6,-23400(13); lis 4,-32700; addi 0,4,-14372; addi 5,6,1; rlwinm 4,6,2,0,29; stw 5,-23400(13); add 4,0,4; stw 3,0x0(4)"
extern "C" void f_8025D950() {}
