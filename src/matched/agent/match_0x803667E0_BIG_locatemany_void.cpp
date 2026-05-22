// 0x803667E0 BIG_locatemany(void (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 26,0x10(1); stw 0,0x2c(1); stw 12,0xc(1); mr 28,3; mr 30,4; mr 29,5; li 26,0; li 27,44; 0:; mr 3,30; li 4,44; bl _s803667E0_0; mr. 31,3; mcrf cr4,cr0; beq cr4,1f; stb 26,0x0(31); 1:; mr 4,30; mr 3,28; bl _s803667E0_1; stw 3,0x0(29); addi 29,29,4; beq cr4,2f; stb 27,0x0(31); addi 31,31,1; mr 30,31; cmpwi 30,0; bne 0b; 2:; lwz 0,0x2c(1); lwz 12,0xc(1); mtspr 8,0; lmw 26,0x10(1); mtcrf 8,12; addi 1,1,40"
extern "C" void _s803667E0_0();
extern "C" void _s803667E0_1();
extern "C" void f_803667E0() {}
