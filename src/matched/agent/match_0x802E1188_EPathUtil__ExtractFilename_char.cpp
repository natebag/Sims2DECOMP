// 0x802E1188 EPathUtil::ExtractFilename(char (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; cmpw 31,30; beq 0f; bl _s802E1188_0; 0:; mr 3,31; bl _s802E1188_1; mr 3,31; li 4,47; bl _s802E1188_2; mr. 3,3; bne 1f; mr 3,31; li 4,58; bl _s802E1188_3; mr. 3,3; bne 1f; mr 3,31; b 2f; 1:; subf 4,31,3; add 4,30,4; mr 3,31; addi 4,4,1; bl _s802E1188_4; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E1188_0();
extern "C" void _s802E1188_1();
extern "C" void _s802E1188_2();
extern "C" void _s802E1188_3();
extern "C" void _s802E1188_4();
extern "C" void f_802E1188() {}
