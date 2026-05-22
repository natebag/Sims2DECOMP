// 0x80242690 isdigit (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32704; addi 9,9,-935; lbzx 3,3,9; rlwinm 3,3,0,29,29"
extern "C" int f_80242690() {}
