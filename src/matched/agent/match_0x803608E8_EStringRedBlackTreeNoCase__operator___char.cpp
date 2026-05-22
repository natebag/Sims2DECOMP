// 0x803608E8 EStringRedBlackTreeNoCase::operator[](char (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; bl _s803608E8_0; mr. 31,3; beq 0f; addi 3,31,28; mr 4,30; bl _s803608E8_1; cmpwi 3,0; bne 0f; addi 3,31,24; b 1f; 0:; mr 3,29; mr 4,31; mr 5,30; li 6,0; bl _s803608E8_2; addi 3,3,24; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803608E8_0();
extern "C" void _s803608E8_1();
extern "C" void _s803608E8_2();
extern "C" void f_803608E8() {}
