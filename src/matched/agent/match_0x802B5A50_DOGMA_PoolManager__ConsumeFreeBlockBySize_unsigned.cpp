// 0x802B5A50 DOGMA_PoolManager::ConsumeFreeBlockBySize(unsigned (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(3); rlwinm 4,4,0,0,29; lbz 0,0x10(3); lwzx 8,4,11; lwz 9,0x1c(3); rlwinm 0,0,2,0,29; lwzx 10,8,0; addi 9,9,-1; stw 9,0x1c(3); stwx 10,4,11; lwz 0,0x10(3); andi. 9,0,4; beq 0f; cmpwi 10,0; beq 0f; lbz 0,0x12(3); li 9,0; rlwinm 0,0,2,0,29; stwx 9,10,0; 0:; mr 3,8"
extern "C" void f_802B5A50() {}
