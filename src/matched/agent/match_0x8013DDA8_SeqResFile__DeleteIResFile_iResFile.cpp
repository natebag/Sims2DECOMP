// 0x8013DDA8 SeqResFile::DeleteIResFile(iResFile (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-312(1); mfspr 0,8; stmw 25,0x11c(1); stw 0,0x13c(1); mr 25,3; mr 28,5; mr 27,6; li 26,-250; mr. 30,4; beq 2f; addi 31,1,8; li 5,260; addi 4,31,8; mr 3,31; bl _s8013DDA8_0; li 29,-250; mr 4,28; mr 3,31; bl _s8013DDA8_1; mulli 4,27,20; mr 3,31; addi 4,4,208; add 4,25,4; bl _s8013DDA8_2; cmpwi 3,0; beq 0f; lwz 9,0xc(30); mr 4,31; lha 3,0x20(9); lwz 0,0x24(9); add 3,30,3; mtspr 8,0; blrl; mr 29,3; 0:; cmpwi 29,0; beq 1f; mr 26,29; 1:; lwz 9,0xc(30); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 26,-94; beq 2f; cmpwi 26,-45; 2:; mr 3,26; lwz 0,0x13c(1); mtspr 8,0; lmw 25,0x11c(1); addi 1,1,312"
extern "C" void _s8013DDA8_0();
extern "C" void _s8013DDA8_1();
extern "C" void _s8013DDA8_2();
extern "C" void f_8013DDA8() {}
