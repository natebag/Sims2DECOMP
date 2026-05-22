// 0x8003489C ESim::HasQueuedOperation(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x43c(3); cmpwi 0,0; bgt 0f; lwz 3,0x520(3); blr; 0:; li 3,1"
extern "C" int f_8003489C() {}
