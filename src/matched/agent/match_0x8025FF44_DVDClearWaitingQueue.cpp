// 0x8025FF44 __DVDClearWaitingQueue (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32694; addi 3,3,-17096; stw 3,0x0(3); addi 5,3,8; addi 4,3,16; stw 3,0x4(3); addi 3,3,24; stw 5,0x0(5); stw 5,0x4(5); stw 4,0x0(4); stw 4,0x4(4); stw 3,0x0(3); stw 3,0x4(3)"
extern "C" void f_8025FF44() {}
