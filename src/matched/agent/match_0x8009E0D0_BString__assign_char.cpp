// 0x8009E0D0 BString::assign(char, (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,5; mr 29,3; stb 4,0x8(1); cmpwi 31,-1; bne 0f; bl _s8009E0D0_0; 0:; mr 3,29; bl _s8009E0D0_1; cmplwi 3,1; bgt 1f; cmpwi 31,0; beq 2f; mr 3,29; bl _s8009E0D0_2; addi 0,31,1; cmplw 3,0; bge 2f; 1:; bl _s8009E0D0_3; li 4,16; li 5,0; bl _s8009E0D0_4; lbz 4,0x8(1); mr 5,31; extsb 4,4; bl _s8009E0D0_5; mr 30,3; mr 3,29; bl _s8009E0D0_6; stw 30,0x0(29); b 5f; 2:; li 30,0; cmplw 30,31; bge 4f; 3:; mr 3,29; bl _s8009E0D0_7; lbz 0,0x8(1); stbx 0,3,30; addi 30,30,1; cmplw 30,31; blt 3b; 4:; mr 3,29; bl _s8009E0D0_8; mr 30,3; bl _s8009E0D0_9; stbx 3,30,31; lwz 9,0x0(29); stw 31,0x4(9); 5:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8009E0D0_0();
extern "C" void _s8009E0D0_1();
extern "C" void _s8009E0D0_2();
extern "C" void _s8009E0D0_3();
extern "C" void _s8009E0D0_4();
extern "C" void _s8009E0D0_5();
extern "C" void _s8009E0D0_6();
extern "C" void _s8009E0D0_7();
extern "C" void _s8009E0D0_8();
extern "C" void _s8009E0D0_9();
extern "C" void f_8009E0D0() {}
