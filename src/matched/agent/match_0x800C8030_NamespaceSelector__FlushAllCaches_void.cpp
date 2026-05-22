// 0x800C8030 NamespaceSelector::FlushAllCaches(void) (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 29,3; addi 31,1,8; addi 3,29,16; li 28,0; bl _s800C8030_0; addi 30,1,24; addi 3,29,8; bl _s800C8030_1; stw 28,0x4(31); li 3,24; bl _s800C8030_2; mr 9,3; stw 28,0x8(31); stw 9,0x4(31); addi 10,29,32; stb 28,0xc(31); addi 3,29,24; stw 28,0x0(9); lwz 11,0x4(31); stw 28,0x4(11); lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 11,0xc(11); lwz 0,0x4(31); lwz 11,0x20(29); stw 0,0x4(30); lwz 9,0x4(10); stw 11,0x8(1); stw 9,0x4(31); lwz 0,0x18(1); lwz 9,0x1c(1); stw 0,0x20(29); stw 9,0x4(10); lwz 0,0x28(29); lwz 11,0x8(31); stw 0,0x8(31); lbz 0,0x14(1); lbz 9,0x2c(29); stw 11,0x28(29); stb 9,0x14(1); stb 0,0x2c(29); bl _s800C8030_3; lwz 3,0x30(29); cmpwi 3,0; beq 0f; bl _s800C8030_4; stw 28,0x30(29); 0:; lwz 0,0x8(31); cmpwi 0,0; beq 1f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s800C8030_5; lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 28,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 28,0x8(31); 1:; lwz 3,0x4(31); cmpwi 3,0; beq 2f; li 4,24; bl _s800C8030_6; 2:; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s800C8030_0();
extern "C" void _s800C8030_1();
extern "C" void _s800C8030_2();
extern "C" void _s800C8030_3();
extern "C" void _s800C8030_4();
extern "C" void _s800C8030_5();
extern "C" void _s800C8030_6();
extern "C" void f_800C8030() {}
