// 0x8008396C TextBlock::TextBlock(unsigned (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lis 11,-32707; mr 28,3; lfs f0,0x711c(11); addi 30,1,16; mr 3,8; stw 10,0x8(1); mr 29,9; mr 0,6; mr 11,7; stfs f0,0x4(30); mr 9,3; mr 6,30; mr 3,28; mr 7,0; stfs f0,0x10(1); mr 8,11; mr 10,29; bl _s8008396C_0; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s8008396C_0();
extern "C" void f_8008396C() {}
