// 0x802B5180 AptValueGC_PoolManager::DeallocateAptValueGC(AptValueGC (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; bl _s802B5180_0; cmpwi 3,0; beq 1f; lbz 9,-21327(13); cmpwi 9,4; bne 0f; lwz 0,0x4(31); li 9,0; rlwimi 0,9,31,0,0; stw 0,0x4(31); b 1f; 0:; cmpwi 9,0; bne 1f; lwz 0,0x0(31); rlwimi 0,9,31,0,0; stw 0,0x0(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802B5180_0();
extern "C" void f_802B5180() {}
