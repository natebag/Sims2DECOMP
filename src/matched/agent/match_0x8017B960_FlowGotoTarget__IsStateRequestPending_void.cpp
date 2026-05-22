// 0x8017B960 FlowGotoTarget::IsStateRequestPending(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x88(3); li 11,1; lwz 0,0x84(3); cmpw 0,9; bne 0f; li 11,0; 0:; mr 3,11"
extern "C" int f_8017B960() {}
