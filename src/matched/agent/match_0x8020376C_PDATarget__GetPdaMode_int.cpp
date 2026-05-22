// 0x8020376C PDATarget::GetPdaMode(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 3,3,332; lwzx 3,3,4"
extern "C" int f_8020376C() {}
