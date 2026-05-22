// 0x80306A4C MemSet32(void (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 5,5,0,0,29; add 0,3,5; cmpw 3,0; beqlr; 0:; stw 4,0x0(3); addi 3,3,4; cmpw 3,0; bne 0b"
extern "C" void f_80306A4C() {}
