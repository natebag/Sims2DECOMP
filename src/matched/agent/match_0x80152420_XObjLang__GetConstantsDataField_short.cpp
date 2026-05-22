// 0x80152420 XObjLang::GetConstantsDataField(short, (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,4; mr 28,5; bl _s80152420_0; li 30,0; cmpwi 3,2; beq 2f; bgt 0f; cmpwi 3,1; beq 1f; b 3f; 0:; cmpwi 3,3; bne 3f; li 30,8192; b 2f; 1:; li 30,16384; 2:; extsh 3,3; bl _s80152420_1; subf 3,3,31; extsh 31,3; cmpwi 31,63; bgt 3f; rlwinm 0,31,7,19,24; or 30,0,30; bl _s80152420_2; cmpw 29,3; bge 3f; rlwinm 0,29,0,25,31; li 3,1; or 0,30,0; sth 0,0x0(28); b 4f; 3:; li 3,0; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80152420_0();
extern "C" void _s80152420_1();
extern "C" void _s80152420_2();
extern "C" void f_80152420() {}
