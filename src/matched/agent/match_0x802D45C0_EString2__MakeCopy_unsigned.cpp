// 0x802D45C0 EString2::MakeCopy(unsigned (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr. 28,4; beq 0f; mr 3,28; bl _s802D45C0_0; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; beq 3f; addi 0,3,1; add 29,0,0; bl _s802D45C0_1; mr 4,29; li 5,0; bl _s802D45C0_2; mr. 31,3; beq 2f; mr 4,28; mr 5,29; mr 3,31; crxor 6,6,6; bl _s802D45C0_3; stw 31,0x0(30); b 4f; 2:; mr 3,30; bl _s802D45C0_4; b 4f; 3:; mr 3,30; bl _s802D45C0_5; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802D45C0_0();
extern "C" void _s802D45C0_1();
extern "C" void _s802D45C0_2();
extern "C" void _s802D45C0_3();
extern "C" void _s802D45C0_4();
extern "C" void _s802D45C0_5();
extern "C" void f_802D45C0() {}
