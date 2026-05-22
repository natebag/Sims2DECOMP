// 0x8024C780 OSAllocFromArenaLo (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-27920(13); addi 4,4,-1; not 5,4; add 0,0,4; and 6,5,0; add 0,6,3; add 0,0,4; and 0,5,0; stw 0,-27920(13); mr 3,6"
extern "C" void f_8024C780() {}
