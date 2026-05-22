// 0x8016A930 SimpleReconObject<NeighborhoodImpl>::~SimpleReconObject(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="beq 0f; mr 3,31; bl _s8016A930_0; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8016A930_0();
extern "C" int f_8016A930() {}
