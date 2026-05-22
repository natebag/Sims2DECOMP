// 0x8009D9D4 BString::operator=(BString (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 31,4; cmpw 29,31; beq 1f; bl _s8009D9D4_0; mr 3,31; bl _s8009D9D4_1; cmpwi 3,-1; beq 0f; lwz 11,0x0(31); stw 11,0x0(29); lwz 9,0xc(11); addi 9,9,1; stw 9,0xc(11); b 1f; 0:; bl _s8009D9D4_2; li 4,16; li 5,0; bl _s8009D9D4_3; mr 30,3; mr 3,31; bl _s8009D9D4_4; mr 6,3; mr 4,31; mr 3,30; li 5,0; bl _s8009D9D4_5; stw 3,0x0(29); 1:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8009D9D4_0();
extern "C" void _s8009D9D4_1();
extern "C" void _s8009D9D4_2();
extern "C" void _s8009D9D4_3();
extern "C" void _s8009D9D4_4();
extern "C" void _s8009D9D4_5();
extern "C" void f_8009D9D4() {}
