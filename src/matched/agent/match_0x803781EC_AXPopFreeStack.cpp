// 0x803781EC __AXPopFreeStack (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32690; addi 4,3,-3232; lwz 0,0x0(4); cmpwi 0,0; mr 3,0; beqlr; lwz 0,0x0(3); stw 0,0x0(4)"
extern "C" void f_803781EC() {}
