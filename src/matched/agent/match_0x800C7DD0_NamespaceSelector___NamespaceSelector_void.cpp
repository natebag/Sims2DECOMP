// 0x800C7DD0 NamespaceSelector::~NamespaceSelector(void) (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; addi 30,31,32; bl _s800C7DD0_0; lwz 0,0x8(30); cmpwi 0,0; beq 0f; lwz 9,0x4(30); mr 3,30; lwz 4,0x4(9); bl _s800C7DD0_1; lwz 9,0x4(30); li 0,0; stw 9,0x8(9); lwz 11,0x4(30); stw 0,0x4(11); lwz 9,0x4(30); stw 9,0xc(9); stw 0,0x8(30); 0:; lwz 3,0x4(30); cmpwi 3,0; beq 1f; li 4,24; bl _s800C7DD0_2; 1:; addi 30,31,24; mr 3,30; bl _s800C7DD0_3; lwz 3,0x4(30); cmpwi 3,0; beq 2f; li 4,20; bl _s800C7DD0_4; 2:; addi 30,31,16; mr 3,30; bl _s800C7DD0_5; lwz 3,0x4(30); cmpwi 3,0; beq 3f; li 4,20; bl _s800C7DD0_6; 3:; addi 30,31,8; mr 3,30; bl _s800C7DD0_7; lwz 3,0x4(30); cmpwi 3,0; beq 4f; li 4,20; bl _s800C7DD0_8; 4:; andi. 0,29,1; beq 5f; mr 3,31; bl _s800C7DD0_9; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800C7DD0_0();
extern "C" void _s800C7DD0_1();
extern "C" void _s800C7DD0_2();
extern "C" void _s800C7DD0_3();
extern "C" void _s800C7DD0_4();
extern "C" void _s800C7DD0_5();
extern "C" void _s800C7DD0_6();
extern "C" void _s800C7DD0_7();
extern "C" void _s800C7DD0_8();
extern "C" void _s800C7DD0_9();
extern "C" void f_800C7DD0() {}
