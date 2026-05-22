// 0x801845C4 GetSelectedActionMenuItem(unsigned (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 3,1; ble 0f; li 3,0; blr; 0:; rlwinm 0,3,2,0,29; addi 9,13,-31480; lwzx 3,9,0"
extern "C" int f_801845C4() {}
