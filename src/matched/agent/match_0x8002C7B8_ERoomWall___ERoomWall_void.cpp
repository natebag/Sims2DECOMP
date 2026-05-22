// 0x8002C7B8 ERoomWall::~ERoomWall(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32698; lwz 30,0x14(31); addi 9,9,-20592; mr 29,4; stw 9,0x3c(31); cmpwi 30,0; beq 1f; 0:; lwz 11,0x0(30); lwz 30,0x8(30); lwz 9,0x0(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; mr. 30,30; bne 0b; 1:; addi 30,31,20; mr 3,30; bl _s8002C7B8_0; mr 3,30; bl _s8002C7B8_1; addi 3,31,3; li 4,2; bl _s8002C7B8_2; mr 3,31; li 4,2; bl _s8002C7B8_3; andi. 0,29,1; beq 2f; mr 3,31; bl _s8002C7B8_4; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8002C7B8_0();
extern "C" void _s8002C7B8_1();
extern "C" void _s8002C7B8_2();
extern "C" void _s8002C7B8_3();
extern "C" void _s8002C7B8_4();
extern "C" void f_8002C7B8() {}
