// 0x802D8C14 EA::Allocator::GeneralAllocator::Shutdown(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; lwz 3,0x4fc(31); cmpwi 3,0; beq 0f; bl _s802D8C14_0; 0:; lwz 0,0x0(31); cmpwi 0,0; beq 4f; li 0,0; lwz 9,0x4(31); stw 0,0x0(31); andi. 0,9,1; beq 1f; mr 3,31; bl _s802D8C14_1; 1:; lwz 9,0x470(31); addi 0,31,1100; mr 29,0; addi 28,31,52; cmpw 9,0; beq 3f; 2:; lwz 30,0x470(31); mr 3,31; mr 4,30; bl _s802D8C14_2; mr 4,30; mr 3,31; bl _s802D8C14_3; lwz 0,0x470(31); cmpw 0,29; bne 2b; 3:; li 0,0; stw 28,0x444(31); stw 0,0x478(31); stw 0,0x474(31); 4:; lwz 30,0x4fc(31); cmpwi 30,0; beq 5f; li 0,0; mr 3,30; stw 0,0x4fc(31); bl _s802D8C14_4; mr 3,30; bl _s802D8C14_5; 5:; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802D8C14_0();
extern "C" void _s802D8C14_1();
extern "C" void _s802D8C14_2();
extern "C" void _s802D8C14_3();
extern "C" void _s802D8C14_4();
extern "C" void _s802D8C14_5();
extern "C" void f_802D8C14() {}
