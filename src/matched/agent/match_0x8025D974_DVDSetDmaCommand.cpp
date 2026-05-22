// 0x8025D974 __DVDSetDmaCommand (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-23396(13); addi 4,13,-27772; addi 0,5,1; stw 0,-23396(13); rlwinm 0,5,2,0,29; stwx 3,4,0"
extern "C" void f_8025D974() {}
