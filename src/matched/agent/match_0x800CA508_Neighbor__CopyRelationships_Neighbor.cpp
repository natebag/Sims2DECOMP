// 0x800CA508 Neighbor::CopyRelationships(Neighbor (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 27,3; mr. 28,4; beq 2f; li 30,0; 0:; lwz 3,-21476(13); mr 4,30; lwz 9,0x0(3); lha 0,0xe0(9); lwz 9,0xe4(9); add 3,3,0; mtspr 8,9; blrl; mr. 30,3; beq 2f; lha 0,0x4(27); cmpw 30,0; beq 1f; lha 0,0x4(28); cmpw 30,0; beq 1f; lwz 3,-21476(13); mr 4,30; li 29,0; lwz 9,0x0(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; mr 31,3; stw 29,0x8(1); mr 3,28; mr 4,31; addi 5,1,8; bl _s800CA508_0; cmpwi 3,0; beq 1f; lwz 5,0x8(1); mr 3,27; mr 4,31; bl _s800CA508_1; stw 29,0xc(1); mr 3,31; mr 4,28; addi 5,1,12; bl _s800CA508_2; cmpwi 3,0; beq 1f; lwz 5,0xc(1); mr 3,31; mr 4,27; bl _s800CA508_3; 1:; cmpwi 30,0; bgt 0b; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s800CA508_0();
extern "C" void _s800CA508_1();
extern "C" void _s800CA508_2();
extern "C" void _s800CA508_3();
extern "C" void f_800CA508() {}
