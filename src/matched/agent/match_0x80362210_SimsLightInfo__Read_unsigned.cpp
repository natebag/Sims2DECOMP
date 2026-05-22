// 0x80362210 SimsLightInfo::Read(unsigned (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,29; li 5,2; bl _s80362210_0; addi 29,29,2; mr 4,29; li 5,2; addi 3,30,2; addi 29,29,2; bl _s80362210_1; mr 4,29; li 5,4; addi 3,30,4; addi 29,29,4; bl _s80362210_2; mr 4,29; li 5,12; addi 3,30,8; addi 29,29,12; bl _s80362210_3; mr 4,29; li 5,4; addi 3,30,20; addi 29,29,4; bl _s80362210_4; mr 4,29; addi 3,30,24; li 5,4; addi 29,29,4; bl _s80362210_5; subf 3,28,29; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80362210_0();
extern "C" void _s80362210_1();
extern "C" void _s80362210_2();
extern "C" void _s80362210_3();
extern "C" void _s80362210_4();
extern "C" void _s80362210_5();
extern "C" void f_80362210() {}
