// 0x80223354 InteractorModule::WallManipulator::AddWallAtTile(CTilePt (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-200(1); mfspr 0,8; stmw 26,0xb0(1); stw 0,0xcc(1); mr 30,6; mr 28,3; mr 26,4; mr 31,5; mr 5,30; bl _s80223354_0; cmpwi 3,0; bne 0f; li 3,0; b 3f; 0:; lwz 27,-21488(13); mr 3,31; mr 4,30; bl _s80223354_1; cmpwi 3,0; beq 1f; mr 3,31; mr 4,30; bl _s80223354_2; lwz 0,0xd4(28); cmpw 0,3; beq 2f; 1:; mr 4,30; mr 3,31; bl _s80223354_3; lwz 4,0xd4(28); addi 29,1,64; addi 28,1,120; mr 5,30; mr 3,31; bl _s80223354_4; li 6,0; mr 5,30; li 4,0; mr 3,31; bl _s80223354_5; addi 3,1,8; mr 4,31; bl _s80223354_6; lwz 9,0x0(27); addi 5,1,8; mr 4,26; lwz 0,0xb4(9); lha 3,0xb0(9); mtspr 8,0; add 3,27,3; blrl; addi 3,1,8; mr 4,26; bl _s80223354_7; addi 4,1,8; mr 3,30; bl _s80223354_8; mr 3,30; bl _s80223354_9; lwz 9,0x0(27); mr 30,3; addi 5,1,8; mr 3,29; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,27,4; blrl; li 6,0; mr 5,30; li 4,0; mr 3,29; bl _s80223354_10; mr 4,29; mr 3,28; bl _s80223354_11; lwz 9,0x0(27); addi 4,1,8; mr 5,28; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,27,3; mtspr 8,0; blrl; mr 3,29; li 4,2; bl _s80223354_12; addi 3,1,8; li 4,2; bl _s80223354_13; 2:; li 3,1; 3:; lwz 0,0xcc(1); mtspr 8,0; lmw 26,0xb0(1); addi 1,1,200"
extern "C" void _s80223354_0();
extern "C" void _s80223354_1();
extern "C" void _s80223354_2();
extern "C" void _s80223354_3();
extern "C" void _s80223354_4();
extern "C" void _s80223354_5();
extern "C" void _s80223354_6();
extern "C" void _s80223354_7();
extern "C" void _s80223354_8();
extern "C" void _s80223354_9();
extern "C" void _s80223354_10();
extern "C" void _s80223354_11();
extern "C" void _s80223354_12();
extern "C" void _s80223354_13();
extern "C" void f_80223354() {}
