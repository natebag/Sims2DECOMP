// 0x8009F518 BString::find_first_not_of(char (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,5; mr. 31,4; beq 0f; mr 3,31; bl _s8009F518_0; mr 6,3; b 1f; 0:; li 6,0; 1:; mr 3,30; mr 4,31; mr 5,29; bl _s8009F518_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8009F518_0();
extern "C" void _s8009F518_1();
extern "C" void f_8009F518() {}
