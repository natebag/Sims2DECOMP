// 0x8024C7AC OSAllocFromArenaHi (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 0,4,-1; lwz 4,-23680(13); not 0,0; and 4,4,0; subf 4,3,4; and 3,4,0; stw 3,-23680(13)"
extern "C" void f_8024C7AC() {}
