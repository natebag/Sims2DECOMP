// 0x80386CE0 __CARDGetStatusEx (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); mr. 30,4; stw 29,0x1c(1); addi 29,5,0; blt 0f; cmpwi 30,127; blt 1f; 0:; li 3,-128; b 4f; 1:; addi 4,1,20; bl _s80386CE0_0; cmpwi 3,0; bge 2f; b 4f; 2:; lwz 3,0x14(1); bl _s80386CE0_1; rlwinm 0,30,6,0,25; add 30,3,0; lwz 3,0x14(1); mr 4,30; bl _s80386CE0_2; mr. 31,3; blt 3f; addi 3,29,0; addi 4,30,0; li 5,64; bl _s80386CE0_3; 3:; lwz 3,0x14(1); mr 4,31; bl _s80386CE0_4; 4:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80386CE0_0();
extern "C" void _s80386CE0_1();
extern "C" void _s80386CE0_2();
extern "C" void _s80386CE0_3();
extern "C" void _s80386CE0_4();
extern "C" void f_80386CE0() {}
