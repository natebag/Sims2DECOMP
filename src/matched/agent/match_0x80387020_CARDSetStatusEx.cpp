// 0x80387020 __CARDSetStatusEx (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 6,-32712; stw 0,0x4(1); addi 6,6,-4300; stwu 1,-32(1); stw 31,0x1c(1); addi 31,3,0; bl _s80387020_0; cmpwi 3,0; bge 0f; b 1f; 0:; mr 3,31; bl _s80387020_1; 1:; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80387020_0();
extern "C" void _s80387020_1();
extern "C" void f_80387020() {}
