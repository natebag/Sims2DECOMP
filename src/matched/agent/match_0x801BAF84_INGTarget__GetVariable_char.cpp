// 0x801BAF84 INGTarget::GetVariable(char (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; li 3,128; bl _s801BAF84_0; mr 31,3; li 4,0; li 5,128; bl _s801BAF84_1; lis 4,-32705; mr 3,30; addi 4,4,5244; bl _s801BAF84_2; cmpwi 3,0; bne 0f; lis 9,-32705; addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(31); sth 0,0x4(31); stb 8,0x6(31); b 2f; 0:; lis 4,-32705; mr 3,30; addi 4,4,5256; bl _s801BAF84_3; cmpwi 3,0; bne 1f; lis 4,-32705; mr 3,31; addi 4,4,-8800; li 5,3; crxor 6,6,6; bl _s801BAF84_4; b 2f; 1:; lis 4,-32705; mr 3,30; addi 4,4,5276; bl _s801BAF84_5; cmpwi 3,0; bne 2f; lis 4,-32705; mr 3,31; addi 4,4,-8800; li 5,7; crxor 6,6,6; bl _s801BAF84_6; 2:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801BAF84_0();
extern "C" void _s801BAF84_1();
extern "C" void _s801BAF84_2();
extern "C" void _s801BAF84_3();
extern "C" void _s801BAF84_4();
extern "C" void _s801BAF84_5();
extern "C" void _s801BAF84_6();
extern "C" void f_801BAF84() {}
