// 0x8038443C CARDRead (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 7,-32712; stw 0,0x4(1); addi 7,7,-4300; stwu 1,-32(1); stw 31,0x1c(1); addi 31,3,0; bl _s8038443C_0; cmpwi 3,0; bge 0f; b 1f; 0:; lwz 3,0x0(31); bl _s8038443C_1; 1:; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8038443C_0();
extern "C" void _s8038443C_1();
extern "C" void f_8038443C() {}
