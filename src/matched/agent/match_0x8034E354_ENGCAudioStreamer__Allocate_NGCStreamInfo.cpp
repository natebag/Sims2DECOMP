// 0x8034E354 ENGCAudioStreamer::Allocate(NGCStreamInfo (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 28,4; mr 30,5; mr 29,6; bl _s8034E354_0; addi 3,1,8; bl _s8034E354_1; mr 31,3; cmpwi 31,-1; beq 0f; lwz 3,0x8(1); mr 5,30; mr 6,29; mr 4,28; bl _s8034E354_2; mr 30,3; bl _s8034E354_3; lwz 4,0x8(1); lis 3,-32702; addi 3,3,8844; addi 4,4,36; bl _s8034E354_4; lwz 9,0x8(1); lis 7,-32715; mr 5,30; addi 7,7,-5440; lwz 11,0x10(9); addi 3,9,36; lwz 4,0x68(9); li 8,1; lwz 6,0x8(11); bl _s8034E354_5; b 1f; 0:; bl _s8034E354_6; 1:; stw 31,0x40(28); mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8034E354_0();
extern "C" void _s8034E354_1();
extern "C" void _s8034E354_2();
extern "C" void _s8034E354_3();
extern "C" void _s8034E354_4();
extern "C" void _s8034E354_5();
extern "C" void _s8034E354_6();
extern "C" void f_8034E354() {}
