// 0x802B5AA4 DOGMA_PoolManager::AddFreeBlockBySize(void (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x1c(3); rlwinm 10,5,0,0,29; lwz 11,0x0(3); addi 9,9,1; lwzx 8,10,11; stw 9,0x1c(3); stwx 4,10,11; lbz 0,0x10(3); rlwinm 0,0,2,0,29; stwx 8,4,0; lwz 9,0x10(3); andi. 0,9,8; beq 0f; lbz 0,0x11(3); rlwinm 0,0,2,0,29; stwx 5,4,0; 0:; lwz 0,0x10(3); andi. 9,0,4; beqlr; cmpwi 8,0; beq 1f; lbz 0,0x12(3); rlwinm 0,0,2,0,29; stwx 4,8,0; 1:; lbz 0,0x12(3); li 9,0; rlwinm 0,0,2,0,29; stwx 9,4,0"
extern "C" void f_802B5AA4() {}
