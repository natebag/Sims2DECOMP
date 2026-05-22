// 0x80022050 CollisionMap::IsMoveBlocked(int, (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); mr 0,4; mr 31,5; mr 4,3; mr 29,6; mr 5,0; li 6,0; addi 3,1,8; bl _s80022050_0; lwz 11,-21488(13); addi 4,1,8; lwz 9,0x0(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 4f; lwz 3,-21488(13); addi 4,1,8; lwz 9,0x0(3); lha 0,0xf8(9); lwz 9,0xfc(9); add 3,3,0; mtspr 8,9; blrl; andi. 0,3,16; beq 0f; cmpwi 31,0; bne 6f; b 4f; 0:; cmpwi 31,0; bne 6f; lwz 11,-21488(13); addi 30,1,16; mr 3,30; addi 5,1,8; lwz 9,0x0(11); mr 31,30; lha 4,0xa8(9); lwz 0,0xac(9); add 4,11,4; mtspr 8,0; blrl; mr 3,30; mr 4,29; bl _s80022050_1; cmpwi 3,0; beq 5f; mr 4,29; mr 3,31; bl _s80022050_2; cmpwi 3,3; beq 1f; cmpwi 3,5; beq 1f; cmpwi 3,6; beq 1f; cmpwi 3,15; beq 1f; cmpwi 3,23; bne 2f; 1:; li 0,1; b 3f; 2:; li 0,0; 3:; cmpwi 0,0; bne 5f; mr 3,31; li 4,2; bl _s80022050_3; 4:; addi 3,1,8; li 4,2; bl _s80022050_4; li 3,1; b 7f; 5:; mr 3,31; li 4,2; bl _s80022050_5; 6:; addi 3,1,8; li 4,2; bl _s80022050_6; li 3,0; 7:; lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"
extern "C" void _s80022050_0();
extern "C" void _s80022050_1();
extern "C" void _s80022050_2();
extern "C" void _s80022050_3();
extern "C" void _s80022050_4();
extern "C" void _s80022050_5();
extern "C" void _s80022050_6();
extern "C" void f_80022050() {}
