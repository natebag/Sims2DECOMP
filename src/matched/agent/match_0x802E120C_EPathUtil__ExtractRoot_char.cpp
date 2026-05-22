// 0x802E120C EPathUtil::ExtractRoot(char (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; cmpw 31,30; beq 0f; bl _s802E120C_0; 0:; mr 3,31; bl _s802E120C_1; li 4,46; mr 3,30; bl _s802E120C_2; mr 29,3; li 4,47; mr 3,31; bl _s802E120C_3; mr. 3,3; bne 1f; mr 3,31; li 4,58; bl _s802E120C_4; mr. 3,3; beq 2f; 1:; addi 3,3,1; subf 0,31,3; add 3,30,0; b 3f; 2:; mr 3,30; 3:; cmpwi 29,0; beq 4f; cmplw 29,3; bge 5f; 4:; mr 4,3; mr 3,31; bl _s802E120C_5; b 6f; 5:; subf 30,3,29; mr 4,3; mr 3,31; mr 5,30; bl _s802E120C_6; li 0,0; stbx 0,31,30; 6:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802E120C_0();
extern "C" void _s802E120C_1();
extern "C" void _s802E120C_2();
extern "C" void _s802E120C_3();
extern "C" void _s802E120C_4();
extern "C" void _s802E120C_5();
extern "C" void _s802E120C_6();
extern "C" void f_802E120C() {}
