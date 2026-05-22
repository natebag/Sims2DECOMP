// 0x80199A90 CASSelectionTarget::GetLocalizable(char (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8216(1); mfspr 0,8; stmw 30,0x2010(1); stw 0,0x201c(1); lbz 9,0x0(4); li 0,0; mr 31,3; sth 0,0x8(1); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 4,4,1; 0:; lis 3,-32705; addi 3,3,-14692; bl _s80199A90_0; cmpwi 3,0; bne 3f; addi 3,1,8200; li 4,0; mr 30,3; li 5,8; bl _s80199A90_1; lwz 6,0x90(31); cmpwi 6,-1; bne 1f; lis 5,-32705; mr 3,30; addi 5,5,-14268; li 4,8; crxor 6,6,6; bl _s80199A90_2; b 2f; 1:; lis 5,-32705; lwz 7,0x8c(31); addi 5,5,-14264; addi 6,6,1; mr 3,30; li 4,8; crxor 6,6,6; bl _s80199A90_3; 2:; li 0,0; mr 3,30; stb 0,0x7(30); bl _s80199A90_4; addi 4,3,1; addi 5,1,8; mr 3,30; bl _s80199A90_5; b 4f; 3:; li 3,0; b 5f; 4:; addi 3,1,8; bl _s80199A90_6; addi 3,1,8; bl _s80199A90_7; addi 3,1,8; bl _s80199A90_8; addi 3,1,8; bl _s80199A90_9; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s80199A90_10; mr 30,3; addi 4,1,8; bl _s80199A90_11; mr 3,30; 5:; lwz 0,0x201c(1); mtspr 8,0; lmw 30,0x2010(1); addi 1,1,8216"
extern "C" void _s80199A90_0();
extern "C" void _s80199A90_1();
extern "C" void _s80199A90_2();
extern "C" void _s80199A90_3();
extern "C" void _s80199A90_4();
extern "C" void _s80199A90_5();
extern "C" void _s80199A90_6();
extern "C" void _s80199A90_7();
extern "C" void _s80199A90_8();
extern "C" void _s80199A90_9();
extern "C" void _s80199A90_10();
extern "C" void _s80199A90_11();
extern "C" void f_80199A90() {}
