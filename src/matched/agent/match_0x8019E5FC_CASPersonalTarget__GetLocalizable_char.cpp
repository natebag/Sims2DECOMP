// 0x8019E5FC CASPersonalTarget::GetLocalizable(char (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8216(1); mfspr 0,8; stmw 30,0x2010(1); stw 0,0x201c(1); mr 30,4; li 0,0; lbz 9,0x0(30); mr 31,3; sth 0,0x8(1); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 30,30,1; 0:; lis 3,-32705; mr 4,30; addi 3,3,-12384; li 5,16; bl _s8019E5FC_0; cmpwi 3,0; bne 1f; addi 3,30,16; bl _s8019E5FC_1; extsh 4,3; addi 5,1,8; mr 3,31; bl _s8019E5FC_2; b 6f; 1:; lis 3,-32705; mr 4,30; addi 3,3,-12364; li 5,12; bl _s8019E5FC_3; cmpwi 3,0; bne 2f; mr 3,31; mr 4,30; addi 5,1,8; bl _s8019E5FC_4; b 6f; 2:; lis 3,-32705; mr 4,30; addi 3,3,-12348; li 5,19; bl _s8019E5FC_5; cmpwi 3,0; bne 3f; addi 3,30,19; bl _s8019E5FC_6; extsh 4,3; addi 5,1,8; mr 3,31; bl _s8019E5FC_7; b 6f; 3:; lis 3,-32705; mr 4,30; addi 3,3,-12716; bl _s8019E5FC_8; cmpwi 3,0; bne 5f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12328; addi 3,1,8200; crxor 6,6,6; bl _s8019E5FC_9; lwz 9,0x2008(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; addi 3,1,8; bl _s8019E5FC_10; b 6f; 5:; li 3,0; b 7f; 6:; addi 3,1,8; bl _s8019E5FC_11; addi 3,1,8; bl _s8019E5FC_12; addi 3,1,8; bl _s8019E5FC_13; addi 3,1,8; bl _s8019E5FC_14; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s8019E5FC_15; mr 30,3; addi 4,1,8; bl _s8019E5FC_16; mr 3,30; 7:; lwz 0,0x201c(1); mtspr 8,0; lmw 30,0x2010(1); addi 1,1,8216"
extern "C" void _s8019E5FC_0();
extern "C" void _s8019E5FC_1();
extern "C" void _s8019E5FC_2();
extern "C" void _s8019E5FC_3();
extern "C" void _s8019E5FC_4();
extern "C" void _s8019E5FC_5();
extern "C" void _s8019E5FC_6();
extern "C" void _s8019E5FC_7();
extern "C" void _s8019E5FC_8();
extern "C" void _s8019E5FC_9();
extern "C" void _s8019E5FC_10();
extern "C" void _s8019E5FC_11();
extern "C" void _s8019E5FC_12();
extern "C" void _s8019E5FC_13();
extern "C" void _s8019E5FC_14();
extern "C" void _s8019E5FC_15();
extern "C" void _s8019E5FC_16();
extern "C" void f_8019E5FC() {}
