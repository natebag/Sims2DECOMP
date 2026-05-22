// 0x80190ABC InteractionHelper::Init(InteractionList (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,4; mr 29,3; mr 3,30; bl _s80190ABC_0; cmpwi 3,0; beq 2f; lwz 0,0x0(30); li 31,0; addi 28,1,8; stw 0,0x8(1); b 1f; 0:; lwz 4,0x8(1); mr 3,29; addi 31,31,1; bl _s80190ABC_1; mr 3,28; bl _s80190ABC_2; 1:; mr 3,30; bl _s80190ABC_3; cmpw 31,3; blt 0b; lwz 0,0x0(29); stw 0,0x4(29); 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80190ABC_0();
extern "C" void _s80190ABC_1();
extern "C" void _s80190ABC_2();
extern "C" void _s80190ABC_3();
extern "C" void f_80190ABC() {}
