// 0x800D6F64 NghResFile::WriteCharacterData(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,-21432(13); bl _s800D6F64_0; li 0,0; lwz 4,-31920(13); li 5,0; addi 3,30,40; sth 0,0x184(30); bl _s800D6F64_1; mr 3,30; li 4,0; bl _s800D6F64_2; mr 31,3; cmpwi 31,1; bne 0f; mr 3,30; li 4,0; bl _s800D6F64_3; mr 31,3; 0:; lwz 3,-26524(13); lwz 9,0x20(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800D6F64_0();
extern "C" void _s800D6F64_1();
extern "C" void _s800D6F64_2();
extern "C" void _s800D6F64_3();
extern "C" void f_800D6F64() {}
