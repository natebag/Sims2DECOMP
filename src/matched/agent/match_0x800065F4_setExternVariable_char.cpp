// 0x800065F4 setExternVariable(char (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 28,0x48(1); stw 0,0x5c(1); lwz 0,-32724(13); mr 30,3; mr 28,4; cmpwi 0,0; beq 1f; mr 4,0; addi 3,1,8; bl _s800065F4_0; lis 4,-32707; addi 3,1,8; addi 4,4,-11592; bl _s800065F4_1; addi 3,1,8; mr 4,30; bl _s800065F4_2; cmpwi 3,0; beq 0f; lis 3,-32707; mr 4,30; addi 3,3,-11584; bl _s800065F4_3; cmpwi 3,0; beq 0f; lis 3,-32707; mr 4,30; addi 3,3,-11572; bl _s800065F4_4; cmpwi 3,0; beq 0f; lis 3,-32707; mr 4,30; addi 3,3,-11556; bl _s800065F4_5; cmpwi 3,0; bne 7f; 0:; li 0,1; li 9,0; lwz 3,-25136(13); li 4,1; stw 0,-32728(13); stw 9,-32724(13); b 2f; 1:; lbz 0,0x0(30); cmpwi 0,95; bne 4f; lis 3,-32707; mr 4,30; addi 3,3,-11540; bl _s800065F4_6; cmpwi 3,0; beq 7f; lis 3,-32707; mr 4,30; addi 3,3,-11532; bl _s800065F4_7; cmpwi 3,0; bne 3f; lwz 3,-25136(13); li 4,1; 2:; bl _s800065F4_8; bl _s800065F4_9; b 7f; 3:; lis 3,-32707; mr 4,30; addi 3,3,-11528; bl _s800065F4_10; cmpwi 3,0; bne 4f; bl _s800065F4_11; b 7f; 4:; lis 9,-32697; addi 9,9,-768; mr 29,9; addi 31,9,36; 5:; lwz 11,0x0(31); addi 31,31,-4; cmpwi 11,0; beq 6f; lwz 9,0x80(11); mr 4,30; mr 5,28; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 6:; cmpw 31,29; bge 5b; 7:; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"
extern "C" void _s800065F4_0();
extern "C" void _s800065F4_1();
extern "C" void _s800065F4_2();
extern "C" void _s800065F4_3();
extern "C" void _s800065F4_4();
extern "C" void _s800065F4_5();
extern "C" void _s800065F4_6();
extern "C" void _s800065F4_7();
extern "C" void _s800065F4_8();
extern "C" void _s800065F4_9();
extern "C" void _s800065F4_10();
extern "C" void _s800065F4_11();
extern "C" void f_800065F4() {}
