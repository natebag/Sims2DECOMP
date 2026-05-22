// 0x8006C998 ScrollingTextBox::~ScrollingTextBox(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32698; lwz 30,0x24(31); addi 9,9,-13072; mr 29,4; stw 9,0x40(31); cmpwi 30,0; beq 0f; bl _s8006C998_0; mr 4,30; bl _s8006C998_1; 0:; lwz 3,0x0(31); cmpwi 3,0; beq 1f; bl _s8006C998_2; 1:; lis 3,-32692; lis 4,-31585; addi 3,3,-17444; ori 4,4,21693; bl _s8006C998_3; li 0,0; andi. 9,29,1; stw 0,0x3c(31); beq 2f; mr 3,31; bl _s8006C998_4; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8006C998_0();
extern "C" void _s8006C998_1();
extern "C" void _s8006C998_2();
extern "C" void _s8006C998_3();
extern "C" void _s8006C998_4();
extern "C" void f_8006C998() {}
