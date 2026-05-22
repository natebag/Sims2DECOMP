// 0x80285740 AptActionQueueC::IncrementDequeLocation(AptActionQueueC::AptActionPool (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x10(3); addi 4,4,20; lwz 9,0x0(3); mulli 0,0,20; add 0,9,0; cmpw 4,0; bne 0f; mr 4,9; 0:; mr 3,4"
extern "C" int f_80285740() {}
