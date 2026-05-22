// 0x80067ABC SAnimator2::removeAllProps(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; li 29,0; addi 11,31,360; lwz 9,0x168(31); lwz 0,0x4(11); subf 0,9,0; srawi. 9,0,2; ble 1f; mr 28,11; lis 27,-32692; li 30,0; 0:; lwz 11,0x168(31); addi 3,27,-27556; addi 29,29,1; lwzx 9,11,30; lwz 4,0x0(9); bl _s80067ABC_0; lwz 9,0x168(31); lwzx 3,9,30; addi 30,30,4; bl _s80067ABC_1; lwz 0,0x4(28); lwz 9,0x168(31); subf 0,9,0; srawi 0,0,2; cmpw 29,0; blt 0b; 1:; lwz 0,0x168(31); stw 0,0x16c(31); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80067ABC_0();
extern "C" void _s80067ABC_1();
extern "C" void f_80067ABC() {}
