// 0x8004B638 make_ingredient_type_array(short, (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; mr. 3,7; bne 0f; li 3,0; b 4f; 0:; li 0,0; cmpw 9,4; sth 0,0x2(3); sth 0,0x6(3); sth 0,0x4(3); sth 9,0x0(3); beq 1f; sth 4,0x2(3); 1:; lha 0,0x0(3); cmpw 0,5; beq 2f; lha 0,0x2(3); cmpw 0,5; beq 2f; sth 5,0x4(3); 2:; lha 0,0x0(3); cmpw 0,6; beq 3f; lha 0,0x2(3); cmpw 0,6; beq 3f; lha 0,0x4(3); cmpw 0,6; beq 3f; sth 6,0x6(3); 3:; lis 6,-32763; li 4,4; addi 6,6,-19048; li 5,2; bl _s8004B638_0; li 3,1; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8004B638_0();
extern "C" void f_8004B638() {}
