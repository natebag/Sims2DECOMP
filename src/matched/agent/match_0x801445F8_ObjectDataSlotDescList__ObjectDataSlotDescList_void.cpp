// 0x801445F8 ObjectDataSlotDescList::ObjectDataSlotDescList(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; lis 9,-32698; addi 9,9,19344; addi 28,29,4; lis 30,-32706; stw 9,0x0(29); addi 30,30,-10420; addi 4,29,12; li 5,64; mr 3,28; bl _s801445F8_0; mr 3,28; mr 4,30; li 5,-1; bl _s801445F8_1; addi 3,29,76; li 4,0; li 5,0; bl _s801445F8_2; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801445F8_0();
extern "C" void _s801445F8_1();
extern "C" void _s801445F8_2();
extern "C" void f_801445F8() {}
