// 0x8006ED78 SimImageMaker::OverrideBackground(unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 3,0x21c(31); cmpwi 3,0; beq 0f; bl _s8006ED78_0; li 0,0; stw 0,0x21c(31); 0:; cmpwi 30,0; beq 1f; lis 3,-32692; mr 4,30; addi 3,3,-7364; li 5,0; li 6,0; bl _s8006ED78_1; stw 3,0x21c(31); 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8006ED78_0();
extern "C" void _s8006ED78_1();
extern "C" void f_8006ED78() {}
