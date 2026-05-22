// 0x8003531C ESim::GetModelPart(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x63c(3); rlwinm 4,4,2,0,29; addi 9,9,104; lwzx 3,9,4"
extern "C" int f_8003531C() {}
