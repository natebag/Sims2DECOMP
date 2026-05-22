// 0x800D6E94 NghResFile::ReadCharacterData(char (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 3,-21432(13); mr 29,5; bl _s800D6E94_0; lis 4,-32706; mr 3,30; addi 4,4,-21644; bl _s800D6E94_1; addi 3,31,40; mr 4,30; bl _s800D6E94_2; li 0,0; stb 29,0x134(31); stw 0,0x20(31); mr 3,31; li 4,0; bl _s800D6E94_3; mr 3,31; li 4,0; li 5,0; bl _s800D6E94_4; mr 30,3; cmpwi 30,1; bne 0f; mr 3,31; li 4,1; bl _s800D6E94_5; mr 3,31; li 4,0; li 5,0; bl _s800D6E94_6; mr 30,3; 0:; lwz 3,-21432(13); bl _s800D6E94_7; lwz 3,-26524(13); lwz 9,0x20(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800D6E94_0();
extern "C" void _s800D6E94_1();
extern "C" void _s800D6E94_2();
extern "C" void _s800D6E94_3();
extern "C" void _s800D6E94_4();
extern "C" void _s800D6E94_5();
extern "C" void _s800D6E94_6();
extern "C" void _s800D6E94_7();
extern "C" void f_800D6E94() {}
