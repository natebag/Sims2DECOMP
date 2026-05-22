// 0x8009F89C BString::compare(char (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,6; mr 30,3; mr 28,4; mr 31,5; cmpwi 29,-1; bne 0f; bl _s8009F89C_0; 0:; mr 3,30; bl _s8009F89C_1; subf 6,31,3; mr 4,31; mr 3,30; mr 5,28; mr 7,29; bl _s8009F89C_2; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8009F89C_0();
extern "C" void _s8009F89C_1();
extern "C" void _s8009F89C_2();
extern "C" void f_8009F89C() {}
