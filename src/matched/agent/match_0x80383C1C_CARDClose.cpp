// 0x80383C1C CARDClose (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; addi 4,1,12; lwz 3,0x0(3); bl _s80383C1C_0; cmpwi 3,0; bge 0f; b 1f; 0:; li 0,-1; stw 0,0x0(31); li 4,0; lwz 3,0xc(1); bl _s80383C1C_1; 1:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80383C1C_0();
extern "C" void _s80383C1C_1();
extern "C" void f_80383C1C() {}
