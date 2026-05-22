// 0x803828A0 __CARDMountCallback (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); addi 29,4,0; cmpwi 29,-3; stw 28,0x10(1); addi 28,3,0; mulli 5,28,272; lis 3,-32688; addi 0,3,-24000; add 31,0,5; beq 4f; bge 0f; cmpwi 29,-5; beq 4f; b 5f; 0:; cmpwi 29,1; beq 3f; bge 5f; cmpwi 29,0; bge 1f; b 5f; 1:; lwz 3,0x24(31); addi 0,3,1; cmpwi 0,7; stw 0,0x24(31); bge 2f; mr 3,28; bl _s803828A0_0; mr. 29,3; blt 5f; b 6f; 2:; mr 3,31; bl _s803828A0_1; mr 29,3; b 5f; 3:; lis 3,-32712; addi 0,3,10400; lis 3,-32712; stw 0,0xdc(31); addi 5,3,-3584; addi 3,28,0; li 4,0; bl _s803828A0_2; cmpwi 3,0; beq 6f; li 0,0; stw 0,0xdc(31); mr 3,28; bl _s803828A0_3; mr. 29,3; blt 5f; b 6f; 4:; addi 3,28,0; addi 4,29,0; bl _s803828A0_4; 5:; lwz 30,0xd0(31); li 0,0; addi 3,31,0; stw 0,0xd0(31); mr 4,29; bl _s803828A0_5; addi 12,30,0; mtspr 8,12; addi 3,28,0; addi 4,29,0; blrl; 6:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s803828A0_0();
extern "C" void _s803828A0_1();
extern "C" void _s803828A0_2();
extern "C" void _s803828A0_3();
extern "C" void _s803828A0_4();
extern "C" void _s803828A0_5();
extern "C" void f_803828A0() {}
