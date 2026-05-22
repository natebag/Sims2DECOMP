// 0x802B512C AptValueGC_PoolManager::AllocateAptValueGC(unsigned (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s802B512C_0; lbz 0,-21327(13); li 9,1; cmpwi 0,4; bne 0f; lwz 0,0x4(3); rlwimi 0,9,31,0,0; stw 0,0x4(3); b 1f; 0:; cmpwi 0,0; bne 1f; lwz 0,0x0(3); rlwimi 0,9,31,0,0; stw 0,0x0(3); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802B512C_0();
extern "C" void f_802B512C() {}
