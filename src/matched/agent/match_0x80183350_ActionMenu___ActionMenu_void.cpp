// 0x80183350 ActionMenu::~ActionMenu(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0xac(31); cmpwi 0,0; beq 0f; lwz 4,0xa8(31); lwz 3,-26524(13); bl _s80183350_0; lwz 4,0xac(31); bl _s80183350_1; li 0,0; stw 0,0xac(31); 0:; lwz 3,0xb0(31); cmpwi 3,0; beq 1f; bl _s80183350_2; li 0,0; stw 0,0xb0(31); 1:; addi 3,31,12; li 4,2; bl _s80183350_3; andi. 0,30,1; beq 2f; mr 3,31; bl _s80183350_4; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80183350_0();
extern "C" void _s80183350_1();
extern "C" void _s80183350_2();
extern "C" void _s80183350_3();
extern "C" void _s80183350_4();
extern "C" void f_80183350() {}
