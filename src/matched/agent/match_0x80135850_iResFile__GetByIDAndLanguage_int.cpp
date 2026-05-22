// 0x80135850 iResFile::GetByIDAndLanguage(int, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; cmpwi 6,0; bne 0f; lwz 9,0xc(11); mr 6,7; lha 3,0x80(9); lwz 0,0x84(9); add 3,11,3; mtspr 8,0; blrl; b 1f; 0:; mr 3,11; li 4,-91; bl _s80135850_0; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80135850_0();
extern "C" void f_80135850() {}
