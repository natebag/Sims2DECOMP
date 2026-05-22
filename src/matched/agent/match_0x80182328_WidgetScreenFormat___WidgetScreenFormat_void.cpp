// 0x80182328 WidgetScreenFormat::~WidgetScreenFormat(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x10(31); cmpwi 0,0; beq 0f; bl _s80182328_0; lwz 4,0x10(31); bl _s80182328_1; 0:; andi. 0,30,1; beq 1f; mr 3,31; bl _s80182328_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80182328_0();
extern "C" void _s80182328_1();
extern "C" void _s80182328_2();
extern "C" void f_80182328() {}
