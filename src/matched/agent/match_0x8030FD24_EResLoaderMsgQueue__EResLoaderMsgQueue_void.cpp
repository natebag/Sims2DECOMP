// 0x8030FD24 EResLoaderMsgQueue::EResLoaderMsgQueue(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8030FD24_0; addi 3,30,76; bl _s8030FD24_1; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8030FD24_0();
extern "C" void _s8030FD24_1();
extern "C" void f_8030FD24() {}
