// 0x8009F964 BString::compare(char, (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 29,5; stb 4,0x8(1); mr 28,6; bl _s8009F964_0; cmplw 29,3; ble 0f; bl _s8009F964_1; 0:; cmpwi 28,-1; bne 1f; bl _s8009F964_2; 1:; cmpwi 28,0; beq 7f; li 30,0; b 3f; 2:; addi 30,30,1; 3:; cmplw 30,28; bge 4f; mr 3,31; bl _s8009F964_3; subf 3,29,3; cmplw 30,3; bge 4f; mr 3,31; bl _s8009F964_4; add 3,3,29; lbz 9,0x8(1); lbzx 0,3,30; cmpw 0,9; beq 2b; 4:; cmpw 30,28; beq 5f; mr 3,31; bl _s8009F964_5; subf 3,29,3; cmpw 30,3; bne 6f; 5:; mr 3,31; bl _s8009F964_6; subf 3,29,3; subf 3,30,3; b 8f; 6:; mr 3,31; bl _s8009F964_7; add 3,3,29; lbz 0,0x8(1); lbzx 3,3,30; extsb 0,0; extsb 3,3; subf 3,0,3; b 8f; 7:; mr 3,31; bl _s8009F964_8; subf 3,29,3; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8009F964_0();
extern "C" void _s8009F964_1();
extern "C" void _s8009F964_2();
extern "C" void _s8009F964_3();
extern "C" void _s8009F964_4();
extern "C" void _s8009F964_5();
extern "C" void _s8009F964_6();
extern "C" void _s8009F964_7();
extern "C" void _s8009F964_8();
extern "C" void f_8009F964() {}
