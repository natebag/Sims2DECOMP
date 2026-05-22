// 0x803834A4 __CARDFormatRegion (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 5,-32712; stw 0,0x4(1); addi 5,5,-4300; stwu 1,-24(1); stw 31,0x14(1); addi 31,3,0; bl _s803834A4_0; cmpwi 3,0; bge 0f; b 1f; 0:; mr 3,31; bl _s803834A4_1; 1:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803834A4_0();
extern "C" void _s803834A4_1();
extern "C" void f_803834A4() {}
