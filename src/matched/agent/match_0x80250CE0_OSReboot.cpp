// 0x80250CE0 __OSReboot (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-744(1); stw 31,0x2e4(1); addi 31,4,0; stw 30,0x2e0(1); addi 30,3,0; bl _s80250CE0_0; lis 3,-32472; bl _s80250CE0_1; lis 3,-32465; bl _s80250CE0_2; addi 3,1,24; bl _s80250CE0_3; addi 3,1,24; bl _s80250CE0_4; li 0,0; stw 0,0x10(1); addi 3,31,0; oris 4,30,32768; addi 5,1,16; bl _s80250CE0_5; lwz 0,0x2ec(1); lwz 31,0x2e4(1); lwz 30,0x2e0(1); addi 1,1,744; mtspr 8,0"
extern "C" void _s80250CE0_0();
extern "C" void _s80250CE0_1();
extern "C" void _s80250CE0_2();
extern "C" void _s80250CE0_3();
extern "C" void _s80250CE0_4();
extern "C" void _s80250CE0_5();
extern "C" void f_80250CE0() {}
