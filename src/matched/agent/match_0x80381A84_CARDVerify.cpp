// 0x80381A84 __CARDVerify (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s80381A84_0; cmpwi 3,0; bge 0f; b 4f; 0:; addi 3,30,0; li 4,0; bl _s80381A84_1; addi 31,3,0; addi 3,30,0; li 4,0; bl _s80381A84_2; add 0,31,3; cmpwi 0,1; beq 2f; bge 3f; cmpwi 0,0; bge 1f; b 3f; 1:; li 3,0; b 4f; 2:; li 3,-6; b 4f; 3:; li 3,-6; 4:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80381A84_0();
extern "C" void _s80381A84_1();
extern "C" void _s80381A84_2();
extern "C" void f_80381A84() {}
