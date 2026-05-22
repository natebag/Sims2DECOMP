// 0x800C199C Interaction::SetName(int, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lwz 11,-21508(13); mr 30,3; mr 31,5; cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 0f; bl _s800C199C_0; mr. 11,3; beq 0f; lwz 9,0x0(11); mr 4,31; lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; mr. 31,3; beq 0f; addi 3,1,8; bl _s800C199C_1; lwz 9,0x0(31); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,31,3; mtspr 8,0; blrl; mr 4,3; addi 3,1,8; bl _s800C199C_2; mr 3,30; addi 4,1,8; bl _s800C199C_3; addi 3,1,8; li 4,2; bl _s800C199C_4; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800C199C_0();
extern "C" void _s800C199C_1();
extern "C" void _s800C199C_2();
extern "C" void _s800C199C_3();
extern "C" void _s800C199C_4();
extern "C" void f_800C199C() {}
