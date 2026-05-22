// 0x802B5B18 DOGMA_PoolManager::ToNextValidSize(unsigned (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="andi. 0,4,3; beq 0f; rlwinm 4,4,0,0,29; addi 4,4,4; 0:; lwz 0,0x10(3); rlwinm 0,0,28,28,31; cmplw 4,0; bge 1f; mr 4,0; 1:; mr 3,4"
extern "C" int f_802B5B18() {}
