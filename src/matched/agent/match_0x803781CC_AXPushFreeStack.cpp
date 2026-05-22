// 0x803781CC __AXPushFreeStack (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32690; addi 5,4,-3232; lwz 4,0x0(5); li 0,0; stw 4,0x0(3); stw 3,0x0(5); stw 0,0xc(3)"
extern "C" void f_803781CC() {}
