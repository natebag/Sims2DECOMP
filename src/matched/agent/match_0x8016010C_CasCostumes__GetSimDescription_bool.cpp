// 0x8016010C CasCostumes::GetSimDescription(bool, (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="subfic 0,4,0; adde 4,0,4; rlwinm 4,4,4,0,27; lwzx 11,4,3; add 4,4,3; lwz 0,0x4(4); subf 0,11,0; srawi 0,0,2; cmplw 5,0; blt 0f; li 3,0; blr; 0:; rlwinm 9,5,2,0,29; lwzx 3,11,9"
extern "C" int f_8016010C() {}
