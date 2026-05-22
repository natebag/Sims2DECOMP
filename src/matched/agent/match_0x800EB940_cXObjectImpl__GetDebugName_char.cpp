// 0x800EB940 cXObjectImpl::GetDebugName(char (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 23,0x1c(1); stw 0,0x44(1); mr 27,3; mr 26,4; lwz 9,0x8c(27); mr 25,5; li 24,0; lwz 28,0x54(9); lwz 23,0x18(9); lwz 9,0x0(28); cmpwi 9,0; beq 0f; lwz 24,-4(9); 0:; addi 30,1,8; lis 29,-32706; addi 29,29,-20076; addi 4,30,8; mr 3,30; li 5,8; bl _s800EB940_0; li 31,0; mr 3,30; mr 4,29; li 5,-1; bl _s800EB940_1; addi 30,25,-1; b 2f; 1:; addi 31,31,1; 2:; cmpw 31,24; bge 3f; lwz 10,0x0(28); rlwinm 9,31,2,0,29; lwz 11,0x88(27); lwzx 0,10,9; cmpw 0,11; bne 1b; addi 3,1,8; bl _s800EB940_2; mr 4,31; addi 3,1,8; bl _s800EB940_3; 3:; mr 3,23; bl _s800EB940_4; mr 29,3; mr 0,30; cmpw 0,29; ble 4f; mr 0,29; 4:; mr. 29,0; ble 5f; mr 4,23; mr 3,26; mr 5,29; li 31,0; crxor 6,6,6; bl _s800EB940_5; addi 0,29,6; stbx 31,26,29; cmpw 0,25; bge 5f; li 0,91; addi 3,1,8; stbx 0,26,29; bl _s800EB940_6; addi 29,29,1; mr 30,3; addi 3,1,8; bl _s800EB940_7; mr 4,3; mr 5,30; add 3,26,29; crxor 6,6,6; bl _s800EB940_8; add 29,29,30; li 0,93; stbx 0,26,29; addi 29,29,1; stbx 31,26,29; 5:; mr 3,29; lwz 0,0x44(1); mtspr 8,0; lmw 23,0x1c(1); addi 1,1,64"
extern "C" void _s800EB940_0();
extern "C" void _s800EB940_1();
extern "C" void _s800EB940_2();
extern "C" void _s800EB940_3();
extern "C" void _s800EB940_4();
extern "C" void _s800EB940_5();
extern "C" void _s800EB940_6();
extern "C" void _s800EB940_7();
extern "C" void _s800EB940_8();
extern "C" void f_800EB940() {}
