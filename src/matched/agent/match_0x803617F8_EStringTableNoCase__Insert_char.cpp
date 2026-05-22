// 0x803617F8 EStringTableNoCase::Insert(char (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr 28,5; bl _s803617F8_0; mr 29,3; mr 5,30; mr 3,31; mr 4,29; bl _s803617F8_1; cmpwi 3,0; li 3,0; bne 0f; mr 3,31; mr 4,29; mr 5,30; mr 6,28; bl _s803617F8_2; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803617F8_0();
extern "C" void _s803617F8_1();
extern "C" void _s803617F8_2();
extern "C" void f_803617F8() {}
