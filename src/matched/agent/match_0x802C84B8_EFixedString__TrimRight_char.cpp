// 0x802C84B8 EFixedString::TrimRight(char (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s802C84B8_0; mr. 31,3; beq 2f; lwz 9,0x0(30); mr 3,29; add 9,31,9; lbz 4,-1(9); extsb 4,4; bl _s802C84B8_1; cmpwi 3,0; beq 2f; 0:; addi 31,31,-1; cmpwi 31,0; beq 1f; lwz 9,0x0(30); mr 3,29; add 9,31,9; lbz 4,-1(9); extsb 4,4; bl _s802C84B8_2; cmpwi 3,0; bne 0b; 1:; mr 5,31; mr 3,30; mr 4,30; bl _s802C84B8_3; 2:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802C84B8_0();
extern "C" void _s802C84B8_1();
extern "C" void _s802C84B8_2();
extern "C" void _s802C84B8_3();
extern "C" void f_802C84B8() {}
