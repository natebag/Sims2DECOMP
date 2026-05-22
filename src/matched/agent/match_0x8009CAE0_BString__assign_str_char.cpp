// 0x8009CAE0 BString::assign_str(char (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,5; mr 31,3; mr 30,4; cmpwi 29,-1; bne 0f; bl _s8009CAE0_0; 0:; mr 3,31; bl _s8009CAE0_1; cmplwi 3,1; bgt 1f; cmpwi 29,0; beq 3f; mr 3,31; bl _s8009CAE0_2; addi 0,29,1; cmplw 3,0; bge 2f; 1:; bl _s8009CAE0_3; li 4,16; li 5,0; bl _s8009CAE0_4; mr 4,30; mr 5,29; bl _s8009CAE0_5; mr 30,3; mr 3,31; bl _s8009CAE0_6; stw 30,0x0(31); b 4f; 2:; mr 3,31; bl _s8009CAE0_7; mr 4,30; mr 5,29; bl _s8009CAE0_8; 3:; mr 3,31; bl _s8009CAE0_9; cmpwi 3,0; beq 4f; mr 3,31; bl _s8009CAE0_10; mr 30,3; bl _s8009CAE0_11; stbx 3,30,29; 4:; lwz 9,0x0(31); stw 29,0x4(9); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8009CAE0_0();
extern "C" void _s8009CAE0_1();
extern "C" void _s8009CAE0_2();
extern "C" void _s8009CAE0_3();
extern "C" void _s8009CAE0_4();
extern "C" void _s8009CAE0_5();
extern "C" void _s8009CAE0_6();
extern "C" void _s8009CAE0_7();
extern "C" void _s8009CAE0_8();
extern "C" void _s8009CAE0_9();
extern "C" void _s8009CAE0_10();
extern "C" void _s8009CAE0_11();
extern "C" void f_8009CAE0() {}
