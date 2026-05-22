// 0x801357D8 iResFile::AddWithLanguage(Memory::HandleNode (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 25,0x54(1); stw 0,0x74(1); addi 30,1,8; mr 26,3; mr 28,4; mr 27,5; mr 25,9; mr 29,6; addi 4,30,8; li 5,64; mr 3,30; bl _s801357D8_0; lwz 9,0xc(26); mr 4,28; mr 5,27; mr 6,29; lha 3,0xf8(9); mr 7,30; lwz 0,0xfc(9); mr 8,25; add 3,26,3; mtspr 8,0; blrl; lwz 0,0x74(1); mtspr 8,0; lmw 25,0x54(1); addi 1,1,112"
extern "C" void _s801357D8_0();
extern "C" void f_801357D8() {}
