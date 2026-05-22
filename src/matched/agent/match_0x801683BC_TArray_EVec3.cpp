// 0x801683BC TArray<EVec3, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="extsb 0,0; cmpwi 0,1; ble 0f; lbz 0,0xef(31); mr 3,30; addi 4,1,8; li 5,1; stb 0,0x8(1); bl _s801683BC_0; lbz 0,0x8(1); extsb 0,0; b 1f; 0:; li 0,0; 1:; stw 0,0xec(31); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s801683BC_0();
extern "C" void f_801683BC() {}
