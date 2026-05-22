// 0x80383534 CARDFormat (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s80383534_0; lis 5,-32712; addi 4,3,0; addi 5,5,-4300; addi 3,31,0; bl _s80383534_1; cmpwi 3,0; bge 0f; b 1f; 0:; mr 3,31; bl _s80383534_2; 1:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80383534_0();
extern "C" void _s80383534_1();
extern "C" void _s80383534_2();
extern "C" void f_80383534() {}
