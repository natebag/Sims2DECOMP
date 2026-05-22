// 0x800ED0E4 ObjectFolderImpl::Init(char (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 26,5; mr 27,4; li 3,16; bl _s800ED0E4_0; addi 29,31,1360; mr 30,3; addi 28,31,1092; bl _s800ED0E4_1; stw 30,0x3c(31); mr 4,27; stw 26,0x65c(31); mr 3,29; bl _s800ED0E4_2; mr 4,29; mr 3,28; bl _s800ED0E4_3; lis 4,-32706; li 5,-1; addi 4,4,-19844; mr 3,28; bl _s800ED0E4_4; mr 3,29; bl _s800ED0E4_5; mr 3,28; bl _s800ED0E4_6; lwz 11,-21412(13); cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 0:; mr 3,31; bl _s800ED0E4_7; bl _s800ED0E4_8; li 0,1; li 3,220; stw 0,0x38(31); li 4,0; bl _s800ED0E4_9; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800ED0E4_0();
extern "C" void _s800ED0E4_1();
extern "C" void _s800ED0E4_2();
extern "C" void _s800ED0E4_3();
extern "C" void _s800ED0E4_4();
extern "C" void _s800ED0E4_5();
extern "C" void _s800ED0E4_6();
extern "C" void _s800ED0E4_7();
extern "C" void _s800ED0E4_8();
extern "C" void _s800ED0E4_9();
extern "C" void f_800ED0E4() {}
