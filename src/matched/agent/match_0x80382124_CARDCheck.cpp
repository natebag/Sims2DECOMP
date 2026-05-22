// 0x80382124 CARDCheck (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32712; stw 0,0x4(1); addi 5,4,-4300; stwu 1,-24(1); stw 31,0x14(1); addi 31,3,0; addi 4,1,12; bl _s80382124_0; cmpwi 3,0; blt 1f; addic. 0,1,12; bne 0f; b 1f; 0:; mr 3,31; bl _s80382124_1; 1:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80382124_0();
extern "C" void _s80382124_1();
extern "C" void f_80382124() {}
