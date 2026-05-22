// 0x802F241C EMirrorPortal::~EMirrorPortal(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 3,0x44(31); cmpwi 3,0; beq 0f; bl _s802F241C_0; li 0,0; stw 0,0x44(31); 0:; bl _s802F241C_1; lwz 4,0x34(31); bl _s802F241C_2; lwz 30,0x40(31); bl _s802F241C_3; mr 4,30; bl _s802F241C_4; lwz 30,0x3c(31); bl _s802F241C_5; mr 4,30; bl _s802F241C_6; andi. 0,29,1; beq 1f; mr 3,31; bl _s802F241C_7; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802F241C_0();
extern "C" void _s802F241C_1();
extern "C" void _s802F241C_2();
extern "C" void _s802F241C_3();
extern "C" void _s802F241C_4();
extern "C" void _s802F241C_5();
extern "C" void _s802F241C_6();
extern "C" void _s802F241C_7();
extern "C" void f_802F241C() {}
